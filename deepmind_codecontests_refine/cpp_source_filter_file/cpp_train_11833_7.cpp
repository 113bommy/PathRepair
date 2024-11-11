#include <bits/stdc++.h>
using namespace std;
vector<string> map1(100), map2(100), map3(100);
int n;
bool flipH() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map1[i][j] != map2[i][n - j - 1]) {
        return false;
      }
    }
  }
  return true;
}
bool areSame() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map1[i][j] != map2[i][j]) {
        return false;
      }
    }
  }
  return true;
}
bool checkRot90() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map1[i][j] != map2[n - j - 1][i]) {
        return false;
      }
    }
  }
  return true;
}
bool checkRot270() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (map2[i][j] != map1[n - j - 1][i]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> map1[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> map2[i];
  }
  if (areSame() || checkRot90() || checkRot270() || flipH()) {
    cout << "Yes\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    reverse(map2[i].begin(), map2[i].end());
  }
  if (areSame() || checkRot90() || checkRot270() || flipH()) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
