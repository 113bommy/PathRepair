#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
const long long MAX = 100000000LL * 100000000LL;
const long long MIN = numeric_limits<long long>::min();
const double PI = 3.14159265358979;
const long long MOD = 1000000007LL;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) out << v[i] << " ";
  return out;
}
template <class T>
istream& operator>>(istream& in, vector<T>& v) {
  for (int i = 0; i < v.size(); ++i) in >> v[i];
  return in;
}
template <class L, class R>
istream& operator>>(istream& in, pair<L, R>& p) {
  in >> p.first >> p.second;
  return in;
}
template <class T>
T lexical_cast(string& s) {
  stringstream ss(s);
  T t;
  ss >> t;
  return t;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long cdiv(long long a, long long b) { return (a + b - 1) / b; }
long long inv(long long n, long long mod) {
  long long pow = mod - 2;
  long long ans = 1;
  long long cur = n;
  while (pow > 0) {
    if (pow & 1) {
      ans *= cur;
      ans %= mod;
    }
    pow /= 2;
    cur *= cur;
    cur %= mod;
  }
  return ans;
}
template <class Cont>
void sort(Cont& c) {
  sort(begin(c), end(c));
}
template <class Cont>
void reverse(Cont& c) {
  reverse(begin(c), end(c));
}
bool shit;
long long dfs(int v, vector<pair<int, long long>>& p, vector<vector<int>>& ch,
              vector<long long>& a, vector<long long>& b) {
  long long balance = b[v];
  for (auto to : ch[v]) {
    balance += dfs(to, p, ch, a, b);
    if (balance < (long long)-1 * 1000000000 * 1000000000) {
      shit = true;
    }
  }
  balance -= a[v];
  if (balance < 0) {
    long double nb = (long double)balance * (long double)p[v].second;
    if (nb < (long double)-MAX) shit = true;
    balance *= p[v].second;
  }
  return balance;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  shit = false;
  vector<long long> b(n + 1), a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> b[i + 1];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
  }
  vector<pair<int, long long>> p(n + 1);
  p[1] = {0, 1};
  vector<vector<int>> ch(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int x;
    long long k;
    cin >> x >> k;
    p[i + 2] = {x, k};
    ch[x].push_back(i + 2);
  }
  long long ans = dfs(1, p, ch, a, b);
  if (!shit && ans >= 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
