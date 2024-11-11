#include <bits/stdc++.h>
using namespace std;
template <typename T>
void scan(T& x) {
  x = 0;
  bool neg = 0;
  register T c = getchar();
  if (c == '-') neg = 1, c = getchar();
  while ((c < 48) || (c > 57)) c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  if (neg) x *= -1;
}
template <typename T>
void print(T n) {
  bool neg = 0;
  if (n < 0) n *= -1, neg = 1;
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  --i;
  if (neg) putchar('-');
  while (i >= 0) putchar(snum[i--]);
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char ch) { return string("'") + ch + string("'"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class InputIterator>
string to_string(InputIterator first, InputIterator last) {
  bool start = true;
  string res = "{";
  while (first != last) {
    if (!start) {
      res += ", ";
    }
    start = false;
    res += to_string(*first);
    ++first;
  }
  res += "}";
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename A, typename B>
istream& operator>>(istream& input, pair<A, B>& x) {
  input >> x.first >> x.second;
  return input;
}
template <typename A>
istream& operator>>(istream& input, vector<A>& x) {
  for (auto& i : x) input >> i;
  return input;
}
long long powz(int x, int y, int mod) {
  long long res = 1, a, b;
  a = x;
  b = y;
  while (b) {
    if (b & 1) {
      res *= a;
    }
    b /= 2;
    a *= a;
    a %= mod;
    res %= mod;
  }
  return res;
}
long long nCr(long long n, long long k) {
  long long res = 1;
  if (n < k) return 0;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
mt19937 rng32((int)chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n), b[n];
  cin >> a;
  for (int i = 0; i < 2 * n; i++) {
    a[i]--;
    b[a[i]].push_back(i);
  }
  long long dist = 0, prevx = b[0][0], prevy = b[0][1];
  dist = prevx + prevy;
  for (int i = 1; i < n; i++) {
    int t1 = abs(b[i][0] - prevx) + abs(b[i][1] - prevy);
    int t2 = abs(b[i][1] - prevx) + abs(b[i][0] - prevy);
    if (t2 > t1) {
      dist += t1;
      prevx = b[i][0];
      prevy = b[i][1];
    } else {
      dist += t2;
      prevx = b[i][1];
      prevy = b[i][0];
    }
  }
  cout << dist;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
