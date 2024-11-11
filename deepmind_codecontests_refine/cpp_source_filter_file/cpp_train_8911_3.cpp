#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T &first) {
  return first * first;
}
template <class _T>
inline string tostr(const _T &a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
const long double EPS = 1e-9;
char TEMPORARY_CHAR;
const int INF = 1e9;
inline void fft(vector<complex<long double> > &a, bool invert) {
  int n = (int)a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    long double ang = 2 * PI / len * (invert ? -1 : 1);
    complex<long double> wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      complex<long double> w(1);
      for (int j = 0; j < len / 2; ++j) {
        complex<long double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) a[i] /= n;
}
inline void input(int &a) {
  a = 0;
  while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') &&
         (TEMPORARY_CHAR != '-')) {
  }
  char neg = 0;
  if (TEMPORARY_CHAR == '-') {
    neg = 1;
    TEMPORARY_CHAR = getchar();
  }
  while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {
    a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0';
    TEMPORARY_CHAR = getchar();
  }
  if (neg) a = -a;
}
inline void out(long long a) {
  if (!a) putchar('0');
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  char s[20];
  int i;
  for (i = 0; a; ++i) {
    s[i] = '0' + a % 10;
    a /= 10;
  }
  for (int j = (i)-1; j >= 0; j--) putchar(s[j]);
}
inline int nxt() {
  int(ret);
  input((ret));
  ;
  return ret;
}
struct lnum {
  vector<int> a;
  int base;
  lnum(int num = 0, int base = 1000000000) : base(base) {
    if (!num) a.resize(1);
    while (num) {
      a.push_back(num % base);
      num /= base;
    }
  }
  inline int len() const { return a.size(); }
  lnum &operator=(const lnum &l) {
    if (this != &l) {
      a = l.a;
      base = l.base;
    }
    return *this;
  }
  inline friend lnum operator+(const lnum &l, const lnum &r) {
    lnum ret(0, l.base);
    int base = l.base;
    int ln = l.len(), rn = r.len();
    int n = max(ln, rn);
    ret.a.resize(n);
    int o = 0;
    for (int i = 0; i < n; ++i) {
      int s = o;
      if (i < ln) s += l.a[i];
      if (i < rn) s += r.a[i];
      o = s >= base;
      if (o) s -= base;
      ret.a[i] = s;
    }
    if (o) ret.a.push_back(1);
    return ret;
  }
  inline friend lnum operator-(const lnum &l, const lnum &r) {
    lnum ret(0, l.base);
    int base = l.base;
    int n = l.len();
    int rn = r.len();
    ret.a.resize(n);
    int o = 0;
    for (int i = 0; i < n; ++i) {
      int s = l.a[i] - o;
      if (i < rn) s -= r.a[i];
      o = s < 0;
      if (o) s += base;
      ret.a[i] = s;
    }
    if (ret.len() > 1 && !ret.a.back()) ret.a.pop_back();
    return ret;
  }
  inline friend lnum operator*(const lnum &l, const lnum &r) {
    lnum ret(0, l.base);
    int base = l.base;
    if (l.len() * r.len() > 1000000) {
      vector<complex<long double> > fa(l.a.begin(), l.a.end()),
          fb(r.a.begin(), r.a.end());
      int n = 1;
      while (n < max(l.len(), r.len())) n <<= 1;
      n <<= 1;
      fa.resize(n), fb.resize(n);
      fft(fa, false), fft(fb, false);
      for (int i = 0; i < n; ++i) fa[i] *= fb[i];
      fft(fa, true);
      ret.a.resize(n);
      for (int i = 0; i < n; ++i) ret.a[i] = int(fa[i].real() + 0.5);
      int carry = 0;
      for (int i = 0; i < n; ++i) {
        ret.a[i] += carry;
        carry = ret.a[i] / base;
        ret.a[i] %= base;
      }
    } else {
      ret.a.resize(l.len() + r.len());
      for (int i = 0; i < l.len(); ++i)
        for (int j = 0, carry = 0; j < r.len() || carry; ++j) {
          long long cur = ret.a[i + j] +
                          (long long)l.a[i] * (j < r.len() ? r.a[j] : 0) +
                          carry;
          ret.a[i + j] = cur % base;
          carry = cur / base;
        }
    }
    while (ret.len() > 1 && !ret.a.back()) ret.a.pop_back();
    return ret;
  }
  inline friend lnum operator/(const lnum &l, const int &r) {
    lnum ret(0, l.base);
    ret.a.resize(l.len());
    int carry = 0;
    for (int i = l.len() - 1; i >= 0; --i) {
      long long cur = l.a[i] + (long long)carry * l.base;
      ret.a[i] = cur / r;
      carry = cur % r;
    }
    while (ret.len() > 1 && ret.a.back() == 0) ret.a.pop_back();
    return ret;
  }
  inline friend bool operator<(const lnum &l, const lnum &r) {
    if (l.len() < r.len()) return true;
    if (l.len() > r.len()) return false;
    int n = l.len();
    for (int i = n - 1; i >= 0; --i) {
      if (l.a[i] < r.a[i]) return true;
      if (l.a[i] > r.a[i]) return false;
    }
    return false;
  }
  inline friend bool operator>(const lnum &l, const lnum &r) { return r < l; }
  inline friend bool operator==(const lnum &l, const lnum &r) {
    if (l.len() != r.len()) return false;
    int n = l.len();
    for (int i = n - 1; i; --i) {
      if (l.a[i] != r.a[i]) return false;
    }
    return true;
  }
  inline friend bool operator!=(const lnum &l, const lnum &r) {
    return !(l == r);
  }
  inline void print() {
    if (base == 1000000000) {
      printf("%d", a.back());
      for (int i = a.size() - 2; i >= 0; --i) printf("%09d", a[i]);
    } else {
      for (int i = a.size() - 1; i >= 0; --i) printf("%d", a[i]);
    }
  }
};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main() {
  int(n);
  input((n));
  ;
  int(m);
  input((m));
  ;
  int(k);
  input((k));
  ;
  int b[26];
  memset((b), 0, sizeof(b));
  for (int i = 0; i < (int)(k); i++) b[i] = 1;
  reverse(b, b + 26);
  string ss[n];
  for (int i = 0; i < (int)(n); i++) cin >> ss[i];
  pair<int, int> s, f;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(m); j++) {
      if (ss[i][j] == 'S') s = make_pair(i, j);
      if (ss[i][j] == 'T') f = make_pair(i, j);
    }
  string ans;
  int best = INF;
  do {
    int d[n][m];
    memset(d, 255, sizeof(d));
    queue<pair<int, int> > q;
    q.push(f);
    d[f.first][f.second] = 0;
    while (!q.empty()) {
      pair<int, int> v = q.front();
      q.pop();
      for (int i = 0; i < (int)(4); i++) {
        int first = v.first + dx[i];
        int second = v.second + dy[i];
        if (first >= 0 && first < n && second >= 0 && second < m &&
            d[first][second] == -1 &&
            (ss[first][second] == 'S' || b[ss[first][second] - 'a'])) {
          d[first][second] = d[v.first][v.second] + 1;
          q.push(make_pair(first, second));
        }
      }
    }
    if (d[s.first][s.second] == -1 || d[s.first][s.second] > best) continue;
    vector<pair<int, int> > Q;
    Q.push_back(s);
    char used[n][m];
    memset((used), 0, sizeof(used));
    used[s.first][s.second] = 1;
    string cur;
    while (1) {
      vector<pair<int, int> > QQ;
      char min_c = 'z' + 1;
      for (int t = 0; t < (int)(Q.size()); t++) {
        pair<int, int> v = Q[t];
        for (int i = 0; i < (int)(4); i++) {
          int first = v.first + dx[i];
          int second = v.second + dy[i];
          if (first >= 0 && first < n && second >= 0 && second < m &&
              d[first][second] == d[v.first][v.second] - 1 &&
              (ss[first][second] == 'T' || b[ss[first][second] - 'a'])) {
            if (ss[first][second] < min_c) {
              QQ.clear();
              min_c = ss[first][second];
            }
            if (ss[first][second] == min_c && !used[first][second]) {
              QQ.push_back(make_pair(first, second));
              used[first][second] = 1;
            }
          }
        }
      }
      if (min_c == 'T')
        break;
      else {
        Q = QQ;
        cur += min_c;
      }
    }
    if (d[s.first][s.second] < best) {
      ans = cur;
      best = d[s.first][s.second];
    } else {
      ((ans) = (cur) < (ans) ? (cur) : (ans));
    }
  } while (next_permutation(b, b + 26));
  if (ans == "")
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
