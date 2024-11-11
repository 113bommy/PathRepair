#include <bits/stdc++.h>
using namespace std;
long long INF = 10e9 + 7;
using namespace std;
void cout_vector(vector<long long> &a) {
  for (auto i : a) cout << i << " ";
  cout << '\n';
};
void cout_pair(vector<pair<long long, long long>> &a) {
  for (auto i : a) cout << i.first << " " << i.second << "\n";
  cout << '\n';
};
void cout_matrix(vector<vector<long long>> &a) {
  for (auto i : a) {
    for (auto j : i) cout << j << " ";
    cout << '\n';
  }
  cout << '\n';
};
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a > b) return b;
  return a;
}
long long gcd(long long x, long long y) {
  while (x && y) x > y ? x %= y : y %= x;
  return x + y;
}
long long sum(vector<long long> &a) {
  long long s = 0;
  for (long long i = 0; i < a.size(); i++) s += a[i];
  return s;
}
long long comp(vector<long long> &a) {
  long long ans = 1;
  for (long long i = 0; i < 5; i++) ans *= a[i];
  return ans;
}
bool da(vector<long long> &a, vector<long long> &binar) {
  long long n = a.size();
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (binar[i] == 1)
      ans += a[i];
    else
      ans += -a[i];
  }
  return (ans == 0);
}
void solve() {
  string s;
  cin >> s;
  string ans = "NO";
  for (long long i = 0; i < 5; i++) {
    string t;
    cin >> t;
    if (t[0] == s[0] || t[1] == s[1]) ans = "YES";
  }
  cout << "YES";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  solve();
  return 0;
}
