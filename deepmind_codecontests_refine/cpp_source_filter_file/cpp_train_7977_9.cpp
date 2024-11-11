#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int temp;
  map<int, vector<int>> mpp;
  for (int i = 2; i <= n; i++) {
    cin >> temp;
    mpp[temp].push_back(i);
  }
  for (auto itr = mpp.begin(); itr != mpp.end(); ++itr) {
    vector<int> v = (*itr).second;
    int cnt = 0;
    if (v.size() > 1) {
      for (int j = 0; j < v.size(); j++) {
        if (mpp[v[j]].size() == 0) {
          cnt++;
        }
      }
      if (cnt < 3) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
