#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long to, cost;
  edge() {}
  edge(long long a, long long b) { to = a, cost = b; }
};
const long long dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const long long mod = 1000000007;
struct mint {
  long long x = 0;
  mint(long long y = 0) {
    x = y;
    if (x < 0 || x >= mod) x = (x % mod + mod) % mod;
  }
  mint(const mint& ope) { x = ope.x; }
  mint operator-() { return mint(-x); }
  mint operator+(const mint& ope) { return mint(x) += ope; }
  mint operator-(const mint& ope) { return mint(x) -= ope; }
  mint operator*(const mint& ope) { return mint(x) *= ope; }
  mint operator/(const mint& ope) { return mint(x) /= ope; }
  mint& operator+=(const mint& ope) {
    x += ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint& ope) {
    x += mod - ope.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint& ope) {
    x *= ope.x, x %= mod;
    return *this;
  }
  mint& operator/=(const mint& ope) {
    long long n = mod - 2;
    mint mul = ope;
    while (n) {
      if (n & 1) *this *= mul;
      mul *= mul;
      n >>= 1;
    }
    return *this;
  }
  mint inverse() { return mint(1) / *this; }
  bool operator==(const mint& ope) { return x == ope.x; }
  bool operator!=(const mint& ope) { return x != ope.x; }
};
mint modpow(mint a, long long n) {
  if (n == 0) return mint(1);
  if (n % 2)
    return a * modpow(a, n - 1);
  else
    return modpow(a * a, n / 2);
}
istream& operator>>(istream& is, mint& ope) {
  long long t;
  is >> t, ope.x = t;
  return is;
}
ostream& operator<<(ostream& os, mint& ope) { return os << ope.x; }
ostream& operator<<(ostream& os, const mint& ope) { return os << ope.x; }
bool exceed(long long x, long long y, long long m) { return x >= m / y + 1; }
void mark() { cout << "*" << endl; }
void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }
long long sgn(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long digitnum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret++;
  return ret;
}
long long digitsum(long long x, long long b = 10) {
  long long ret = 0;
  for (; x; x /= b) ret += x % b;
  return ret;
}
string lltos(long long x) {
  string ret;
  for (; x; x /= 10) ret += x % 10 + '0';
  reverse(ret.begin(), ret.end());
  return ret;
}
long long stoll(string& s) {
  long long ret = 0;
  for (auto c : s) ret *= 10, ret += c - '0';
  return ret;
}
template <typename T>
void uniq(T& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& deq) {
  for (int i = 0; i < deq.size(); i++)
    os << deq[i] << (i + 1 == deq.size() ? "" : " ");
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& pair_var) {
  os << "(" << pair_var.first << ", " << pair_var.second << ")";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
  for (typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end();
       itr++) {
    os << "(" << itr->first << ", " << itr->second << ")";
    itr++;
    if (itr != map_var.end()) os << ",";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
  for (typename set<T>::iterator itr = set_var.begin(); itr != set_var.end();
       itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, multiset<T>& set_var) {
  for (typename multiset<T>::iterator itr = set_var.begin();
       itr != set_var.end(); itr++) {
    os << *itr;
    ++itr;
    if (itr != set_var.end()) os << " ";
    itr--;
  }
  return os;
}
template <typename T>
void outa(T a[], long long s, long long t) {
  for (long long i = s; i <= t; i++) {
    cout << a[i];
    if (i < t) cout << " ";
  }
  cout << endl;
}
void dump_func() { cout << endl; }
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) > 0) cout << " ";
  dump_func(std::move(tail)...);
}
long long n, s, e;
long long x[5005], a[5005], b[5005], c[5005], d[5005];
long long dp[5005][5005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s >> e;
  for (long long(i) = (1); (i) <= (n); (i)++) cin >> x[i];
  for (long long(i) = (1); (i) <= (n); (i)++) cin >> a[i];
  for (long long(i) = (1); (i) <= (n); (i)++) cin >> b[i];
  for (long long(i) = (1); (i) <= (n); (i)++) cin >> c[i];
  for (long long(i) = (1); (i) <= (n); (i)++) cin >> d[i];
  for (long long(i) = (0); (i) <= (n); (i)++)
    for (long long(j) = (0); (j) <= (n); (j)++) dp[i][j] = 1e18;
  dp[0][0] = 0;
  long long dif = 0;
  for (long long(i) = (0); (i) <= (n - 1); (i)++) {
    for (long long(j) = (0); (j) <= (n); (j)++) {
      long long bj = j - dif, cost = (j + bj) * (x[i + 1] - x[i]);
      if (i >= 1 && i <= n - 1 && j == 0) dp[i][j] = 1e18;
      if (bj < 0) dp[i][j] = 1e18;
      if (i + 1 == s) {
        if (bj > 0)
          (dp[i + 1][j]) = min((dp[i + 1][j]), (dp[i][j] + c[i + 1] + cost));
        (dp[i + 1][j + 1]) =
            min((dp[i + 1][j + 1]), (dp[i][j] + d[i + 1] + cost));
      } else if (i + 1 == e) {
        if (j > 0)
          (dp[i + 1][j - 1]) =
              min((dp[i + 1][j - 1]), (dp[i][j] + a[i + 1] + cost));
        (dp[i + 1][j]) = min((dp[i + 1][j]), (dp[i][j] + b[i + 1] + cost));
      } else {
        if (j > 0)
          (dp[i + 1][j]) =
              min((dp[i + 1][j]), (dp[i][j] + a[i + 1] + d[i + 1] + cost));
        if (bj > 0)
          (dp[i + 1][j]) =
              min((dp[i + 1][j]), (dp[i][j] + b[i + 1] + c[i + 1] + cost));
        if (j > 0)
          (dp[i + 1][j - 1]) =
              min((dp[i + 1][j - 1]), (dp[i][j] + a[i + 1] + c[i + 1] + cost));
        (dp[i + 1][j + 1]) =
            min((dp[i + 1][j + 1]), (dp[i][j] + b[i + 1] + d[i + 1] + cost));
      }
    }
    if (i + 1 == s) dif++;
    if (i + 1 == e) dif--;
  }
  dump_func(dp[n][0]);
  return 0;
}
