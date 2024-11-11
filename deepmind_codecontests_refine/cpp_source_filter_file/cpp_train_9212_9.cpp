#include <bits/stdc++.h>
using namespace std;
int arr[3][2];
char ans[500][500];
vector<char> v = {'A', 'B', 'C'};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int area = 0;
  for (int i = 0; i < 3; i++) {
    cin >> arr[i][0] >> arr[i][1];
    area += arr[i][0] * arr[i][1];
  }
  int side = (int)sqrt(area);
  if (side * side != area) {
    cout << -1 << endl;
    return 0;
  }
  bool ok1 = true;
  bool ansok = false;
  for (int i = 0; i < 3; i++) {
    if (arr[i][1] == side) swap(arr[i][0], arr[i][1]);
    ok1 &= (arr[i][0] == side);
  }
  if (ok1) {
    int cum = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = cum; j < cum + arr[i][1]; j++) {
        for (int k = 0; k < side; k++) {
          ans[j][k] = v[i];
        }
      }
      cum += arr[i][1];
    }
    ansok = true;
  } else {
    for (int i = 1; i <= 1; i++) {
      if (arr[i][0] != side) continue;
      for (int j = 0; j < arr[i][1]; j++) {
        for (int k = 0; k < side; k++) {
          ans[k][j] = v[i];
        }
      }
      int need = side - arr[i][1];
      bool ok = true;
      int already = 0;
      for (int j = 0; j < 3; j++) {
        if (j == i) continue;
        bool tf = false;
        for (int t = 0; t <= 1; t++) {
          if (arr[j][t] == need) {
            for (int j1 = already; j1 < already + arr[j][1 - t]; j1++) {
              for (int k = side - need; k < side; k++) {
                ans[j1][k] = v[j];
              }
            }
            already = arr[j][1 - t];
            tf = true;
          }
        }
        ok &= tf;
      }
      if (ok) {
        ansok = true;
        break;
      }
    }
  }
  if (!ansok) {
    cout << -1 << endl;
    return 0;
  }
  cout << side << endl;
  for (int i = 0; i < side; i++) {
    for (int j = 0; j < side; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
