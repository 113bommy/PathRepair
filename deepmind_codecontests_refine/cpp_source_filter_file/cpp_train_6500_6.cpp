#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[100005], arrsort[100005];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arrsort[i] = arr[i];
  }
  sort(arrsort, arrsort + n);
  for (int i = 1; i < n; i++) {
    arr[i] += arr[i - 1];
    arrsort[i] += arrsort[i - 1];
  }
  int m;
  cin >> m;
  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      if (l == 1) {
        cout << arr[r - 1] << endl;
      } else {
        cout << arr[r - 1] - arr[l - 2] << endl;
      }
    } else {
      if (l == 1) {
        cout << arrsort[r - 1] << endl;
      } else {
        cout << arrsort[r - 1] - arrsort[l - 2] << endl;
      }
    }
  }
}
