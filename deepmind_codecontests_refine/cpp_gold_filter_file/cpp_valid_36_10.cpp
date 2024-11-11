#include <bits/stdc++.h>
using namespace std;
void display(vector<long long> &a, long long N) {
  for (long long i = 0; i < N; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
vector<long long> SoE(int n) {
  vector<long long> ans;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) ans.push_back(p);
  return ans;
}
string slicer(string s, long long i, long long j) {
  string ans = "";
  for (long long x = i; x < j; x++) {
    ans += s[x];
  }
  return ans;
}
long long subarraySum(vector<long long> A, long long i, long long j) {
  long long ans = 0;
  for (long long x = i; x < j; x++) {
    ans += A[x];
  }
  return ans;
}
long long Max1 = 1e5 + 5;
long long Max2 = 1e7 + 5;
long long Max3 = 1e9 + 5;
void solve() {
  long long n;
  cin >> n;
  string ans = "";
  for (long long i = 0; i < (n / 2); i++) {
    ans += 'a';
  }
  ans += 'b';
  for (long long i = 0; i < (n / 2) - 1; i++) {
    ans += 'a';
  }
  if (n % 2 && n > 1) {
    ans += 'c';
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cout << fixed;
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  int t;
  cin >> t;
  t--;
  while (t--) {
    solve();
  }
  solve();
  return 0;
}
