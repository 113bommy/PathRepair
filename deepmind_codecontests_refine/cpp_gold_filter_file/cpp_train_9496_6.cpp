#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize 03
#pragma GCC optimize("unroll-loops")
using namespace std;
long long gcd(long long a, long long b) { return (a == 0) ? b : gcd(b % a, a); }
long long cnt1(long long x) {
  long long cnt = 0;
  while (x > 0) x &= x - 1, cnt++;
  return cnt;
}
long long fact(long long n) { return n == 0 ? 1LL : n * fact(n - 1); }
long long fact(long long n, long long p) {
  return n == 0 ? 1LL : n * fact(n - 1) % p;
}
long long cnk(long long n, long long k) {
  return n == 1 || k == 1 ? 1 : cnk(n - 1, k) + cnk(n - 1, k - 1);
}
long long pow(long long a, long long n, long long p) {
  if (n == 0) return 1;
  long long t = pow(a, n >> 1, p);
  return t * t % p * (n & 1 ? a : 1) % p;
}
long long back(long long x, long long p) { return pow(x, p - 2, p); }
long long cnk(long long n, long long k, long long p) {
  return fact(n, p) * back(fact(k, p), p) % p * back(fact(n - k, p), p) % p;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
  for (long long i = 0; i < (long long)v.size(); i++) stream >> v[i];
  return stream;
}
template <class T1, class T2>
istream& operator>>(istream& stream, pair<T1, T2>& p) {
  return stream >> p.first >> p.second;
}
template <class T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
  for (long long i = 0; i < (long long)v.size(); i++) stream << v[i] << ' ';
  stream << '\n';
  return stream;
}
template <class T1, class T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& p) {
  return stream << p.first << ' ' << p.second;
}
const long long N = 2000;
long long p[N], c[N];
vector<long long> gr[N];
vector<long long> dfs(long long v) {
  vector<long long> vert;
  for (long long u : gr[v]) {
    auto t = dfs(u);
    vert.insert(vert.end(), t.begin(), t.end());
  }
  if (vert.size() < c[v]) {
    cout << "NO";
    exit(0);
  }
  vert.insert(vert.begin() + c[v], v);
  return vert;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(time(0));
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "? 1 1" << endl;
    string ans;
    cin >> ans;
    cout << "! " << ans;
    return 0;
  }
  cout << "? " << 1 << ' ' << n << endl;
  vector<string> a(n * (n + 1) / 2);
  for (auto& s : a) {
    cin >> s;
    sort(s.begin(), s.end());
  }
  cout << "? " << 1 << ' ' << n - 1 << endl;
  vector<string> b(n * (n - 1) / 2);
  for (auto& s : b) {
    cin >> s;
    sort(s.begin(), s.end());
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<string> diff;
  for (long long i = 0, j = 0; i < a.size() || j < b.size();) {
    if (i == a.size() || j < b.size() && a[i] > b[j])
      diff.push_back(b[j++]);
    else if (j == b.size() || i < a.size() && a[i] < b[j])
      diff.push_back(a[i++]);
    else
      i++, j++;
  }
  sort(diff.begin(), diff.end(),
       [](string& a, string& b) { return a.size() < b.size(); });
  string ans;
  string last = "";
  for (long long i = 0; i < n; i++) {
    long long cnt[26] = {0};
    for (char c : last) cnt[c - 'a']--;
    for (char c : diff[i]) cnt[c - 'a']++;
    for (long long i = 0; i < 26; i++)
      if (cnt[i]) ans.push_back(i + 'a');
    last = diff[i];
  }
  reverse(ans.begin(), ans.end());
  cout << "! " << ans;
}
