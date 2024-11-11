#include <bits/stdc++.h>
using namespace std;
int arr[200005], n, s;
vector<int> ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i], s += arr[i];
  for (int i = 0; i < n; ++i) {
    double z = s - arr[i];
    if (z / (n - 1) == arr[i]) ans.push_back(i + 1);
  }
  int i = 0;
  for (cout << ans.size() << endl; i < ans.size(); cout << ans[i++] << " ")
    ;
  return 0;
}
