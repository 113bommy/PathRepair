#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const long long INF = 1LL << 60;
const long long MAX = 1e9;
const int maxN = 5 * 1024;
long long arr[maxN];
long long add[maxN];
long long arr2[maxN];
int N, M;
int op[maxN][4];
int main() {
  cin >> N >> M;
  for (int i = (0); i < (M); i++) {
    for (int j = (0); j < (4); j++) cin >> op[i][j];
  }
  for (int i = (1); i < (N + 1); i++) add[i] = 0;
  for (int i = (1); i < (N + 1); i++) arr[i] = INF;
  bool ok = true;
  for (int m = (0); m < (M); m++) {
    int type = op[m][0];
    int l = op[m][1], r = op[m][2], k = op[m][3];
    if (type == 1) {
      for (int i = (l); i < (r + 1); i++) arr[i] += k;
      for (int i = (l); i < (r + 1); i++) add[i] += k;
    } else {
      for (int i = (l); i < (r + 1); i++) arr[i] = min(arr[i], (long long)k);
    }
  }
  for (int i = (1); i < (N + 1); i++) arr[i] = min(arr[i] - add[i], MAX);
  for (int i = (1); i < (N + 1); i++) arr2[i] = arr[i];
  if (ok)
    for (int m = (0); m < (M); m++) {
      int type = op[m][0];
      int l = op[m][1], r = op[m][2], k = op[m][3];
      if (type == 1) {
        for (int i = (l); i < (r + 1); i++) arr[i] += k;
      } else {
        long long ma = -INF;
        for (int i = (l); i < (r + 1); i++) ma = max(ma, arr[i]);
        if (ma != k) {
          ok = false;
          break;
        }
      }
    }
  if (!ok) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << arr2[1];
  for (int i = (2); i < (N + 1); i++) cout << " " << min(MAX, arr2[i]);
  cout << endl;
}
