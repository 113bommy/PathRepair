#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]].push_back(i + 1);
  }
  int mini = min(min(mp[1].size(), mp[2].size()), mp[3].size());
  if (mini == 0) {
    cout << 0;
    return 0;
  } else {
    cout << mini << endl;
    for (int i = 0; i < mini; i++) {
      cout << mp[1][i] << " ";
      cout << mp[2][i] << " ";
      cout << mp[3][i] << endl;
    }
    cout << endl;
  }
  return 0;
}
