#include <bits/stdc++.h>
using namespace std;
long long int const delta = 1000000007;
queue<long long int> len[60];
int main() {
  std::ios::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    for (long long int j = 59; j >= 0; j--) {
      if (a[i] & (1 << j)) {
        len[j].push(a[i]);
        break;
      }
    }
  }
  long long int temp = 0;
  vector<long long int> ans;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 60; j++) {
      if (!(temp & (1 << j))) {
        if (len[j].size()) {
          long long int t = len[j].front();
          len[j].pop();
          ans.push_back(t);
          ;
          temp ^= t;
          break;
        }
      }
    }
  }
  if (ans.size() != n) return cout << "No", 0;
  cout << "Yes" << endl;
  for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
