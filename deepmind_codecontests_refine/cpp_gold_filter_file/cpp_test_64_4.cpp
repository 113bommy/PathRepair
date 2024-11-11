#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int mrand() { return abs((int)mt()); }
inline int mrand(int k) { return abs((int)mt()) % k; }
void chemthan() {
  auto ispr = [&](int k) {
    for (int i = 2; i * i <= k; i++) {
      if (k % i == 0) {
        return 0;
      }
    }
    return 1;
  };
  vector<int> prs;
  vector<vector<int>> p10s;
  vector<vector<int>> ip10s;
  for (int it = (0); it < (2); ++it) {
    int pr = INF - mrand(INF / 100);
    while (!ispr(pr)) pr++;
    prs.push_back(pr);
    vector<int> p10;
    vector<int> ip10;
    int i10 = inv(10, pr);
    int t = 1;
    int t2 = 1;
    for (int i = (0); i < (1e6); ++i) {
      p10.push_back(t);
      ip10.push_back(t2);
      t = mult(t, 10, pr);
      t2 = mult(t2, i10, pr);
    }
    p10s.push_back(p10);
    ip10s.push_back(ip10);
  }
  string s;
  cin >> s;
  string x;
  cin >> x;
  reverse((s).begin(), (s).end()), reverse((x).begin(), (x).end());
  for (char& c : s) c -= '0';
  for (char& c : x) c -= '0';
  int n = int((s).size());
  vector<vector<int>> hs;
  vector<map<int, int>> mems;
  for (int ix = (0); ix < (int((prs).size())); ++ix) {
    map<int, int> mem;
    vector<int> h;
    int t = 0;
    for (int i = (0); i < (n); ++i) {
      addmod(t, mult(p10s[ix][i], s[i], prs[ix]), prs[ix]);
      h.push_back(t);
      mem[t] = i;
    }
    hs.push_back(h);
    mems.push_back(mem);
  }
  vector<int> hx;
  vector<vector<int>> hxs;
  for (int ix = (0); ix < (int((prs).size())); ++ix) {
    int t = 0;
    for (int i = (0); i < (int((x).size())); ++i) {
      addmod(t, mult(p10s[ix][i], x[i], prs[ix]), prs[ix]);
    }
    hx.push_back(t);
    {
      vector<int> tmp;
      int t = 0;
      for (int i = (int((x).size())) - 1; i >= (0); --i) {
        t = mult(t, 10, prs[ix]);
        addmod(t, x[i], prs[ix]);
        tmp.push_back(t);
      }
      hxs.push_back(tmp);
    }
  }
  auto calc = [&](int ix, int l, int r) {
    int res = hs[ix][r];
    if (l) submod(res, hs[ix][l - 1], prs[ix]);
    return mult(res, ip10s[ix][l], prs[ix]);
  };
  for (int i = (0); i < (n); ++i) {
    for (int len : {int((x).size()) - 1, int((x).size())}) {
      if (!len) continue;
      if (n <= i + len) continue;
      map<int, int> cnt;
      for (int ix = (0); ix < (int((prs).size())); ++ix) {
        int h = hx[ix];
        submod(h, calc(ix, i, i + len - 1), prs[ix]);
        h = mult(h, p10s[ix][i + len], prs[ix]);
        addmod(h, hs[ix][i + len - 1], prs[ix]);
        if (mems[ix].count(h)) {
          cnt[mems[ix][h]]++;
        } else {
          break;
        }
      }
      for (auto [x, c] : cnt) {
        if (c == int((prs).size()) && i + len <= x) {
          int u = i;
          int v = i + len - 1;
          int w = i + len;
          int t = x;
          cout << n - t << " " << n - w << "\n"
               << n - v << " " << n - u << "\n";
          return;
        }
      }
    }
  }
  for (int i = (0); i < (n); ++i) {
    for (int len : {int((x).size()) - 1, int((x).size())}) {
      if (!len) continue;
      if (i - len < 0) continue;
      map<int, int> cnt;
      for (int ix = (0); ix < (int((prs).size())); ++ix) {
        int t = calc(ix, i - len + 1, i);
        vector<int> len2s;
        if (len == int((x).size()) - 1) {
          len2s.push_back(len);
        } else {
          int lo = i - len + 1, hi = i;
          while (lo < hi) {
            int mi = lo + hi >> 1;
            if (calc(ix, mi, i) != hxs[ix][i - mi]) {
              lo = mi + 1;
            } else {
              hi = mi;
            }
          }
          int mi = lo + hi >> 1;
          int tmp = mi - (i - len + 1);
          if (0 < tmp) {
            len2s.push_back(tmp);
          }
          if (0 < tmp - 1) {
            len2s.push_back(tmp - 1);
          }
        }
        for (int len2 : len2s)
          if (0 <= i - len - len2 + 1) {
            int y = t;
            addmod(y, calc(ix, i - len - len2 + 1, i - len), prs[ix]);
            if (y == hx[ix]) {
              cnt[i - len - len2 + 1]++;
            }
          }
      }
      for (auto [x, c] : cnt) {
        if (c == int((prs).size())) {
          int u = x;
          int v = i - len;
          int w = i - len + 1;
          int t = i;
          cout << n - t << " " << n - w << "\n"
               << n - v << " " << n - u << "\n";
          return;
        }
      }
    }
  }
}
int32_t main(int32_t argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
