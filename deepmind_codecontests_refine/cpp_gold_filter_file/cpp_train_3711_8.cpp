#include <bits/stdc++.h>
using namespace std;
vector<long long> v[70];
int main() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    long long b = 0;
    for (long long j = 60; j >= 0; j--)
      if ((((long long)1) << j) & a) {
        b = j;
        break;
      }
    v[b].push_back(a);
  }
  vector<long long> ans, ans1;
  for (long long i = 59; i >= 0; i--) {
    long long C = 0;
    for (long long j = 0; j < ans.size(); j++) {
      if (C < v[i].size() && (ans[j] & (((long long)1) << i)))
        ans1.push_back(v[i][C]), C++;
      ans1.push_back(ans[j]);
    }
    for (long long j = C; j < v[i].size(); j++) ans1.push_back(v[i][C]);
    ans = ans1;
    ans1.clear();
  }
  long long S = 0;
  for (int i = 0; i < ans.size(); i++) {
    if ((ans[i] ^ S) <= S) {
      cout << "No" << endl;
      return 0;
    }
    S ^= ans[i];
  }
  cout << "Yes" << endl;
  for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
}
