#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<pair<int, int>> v1(n);
  for (int i = 0; i < n; i++) {
    cin >> v1[i].first >> v1[i].second;
  }
  sort(v1.begin(), v1.end());
  if (s < v1[0].first) {
    cout << -1 << endl;
    return 0;
  }
  int mini = 1001;
  int yy;
  bool b1 = false;
  for (int i = 0; i < n; i++) {
    if (v1[i].first == s) {
      if (v1[i].second != 0) {
        continue;
      } else {
        if (mini == 1001) {
          mini = 1002;
          b1 = true;
        }
      }
    } else if (v1[i].first < s) {
      b1 = true;
      if (v1[i].second < mini && v1[i].second != 0) {
        mini = v1[i].second;
      } else if (v1[i].second == 0 && mini == 1001) {
        mini = 1002;
      }
    } else {
      break;
    }
  }
  if (b1 == false) {
    cout << -1 << endl;
    return 0;
  } else {
    if (mini != 1002) {
      cout << (100 - mini) << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
}
