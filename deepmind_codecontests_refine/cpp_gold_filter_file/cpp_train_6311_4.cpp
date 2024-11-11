#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<int> ans;
  if (n >= 2) {
    for (int i = 2; i <= n; i += 2) ans.push_back(i);
    for (int i = 1; i <= n; i += 2) ans.push_back(i);
    for (int i = 2; i <= n; i += 2) ans.push_back(i);
  } else if (n == 1)
    ans.push_back(1);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
