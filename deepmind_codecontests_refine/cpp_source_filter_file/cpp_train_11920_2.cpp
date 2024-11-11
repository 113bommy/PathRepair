#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  vector<int> t;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    t.push_back(a);
    arr.push_back({a, i});
  }
  sort(arr.begin(), arr.end());
  int i, j;
  for (i = 0; i < arr.size(); i++) {
    if (arr[i].second != i) break;
  }
  for (j = arr.size() - 1; j >= 0; j--) {
    if (arr[j].second != j) break;
  }
  if (i == arr.size() || j < 0)
    cout << 0 << " " << 0 << endl;
  else {
    vector<int> res;
    for (int k = 0; k < i; k++) res.push_back(t[k]);
    for (int k = j; k >= i; k--) res.push_back(t[k]);
    for (int k = j + 1; k < n; k++) res.push_back(t[k]);
    bool flag = false;
    for (int k = 0; k < n; k++) {
      if (res[k] >= res[k + 1]) {
        flag = true;
        break;
      }
    }
    if (!flag)
      cout << arr[j].second + 1 << " " << arr[i].second + 1 << endl;
    else
      cout << 0 << " " << 0 << endl;
  }
  return 0;
}
