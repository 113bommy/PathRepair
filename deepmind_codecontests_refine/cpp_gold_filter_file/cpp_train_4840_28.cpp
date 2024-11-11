#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[120][120];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> arr[i][j];
  vector<int> v;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] == 1)
        v.push_back(i);
      else if (arr[i][j] == 2)
        v.push_back(j);
      else if (arr[i][j] == 3) {
        v.push_back(i);
        v.push_back(j);
      }
    }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    bool flag = true;
    for (int j = 0; j < v.size(); j++)
      if (i == v[j]) flag = false;
    if (flag) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
