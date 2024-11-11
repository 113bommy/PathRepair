#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int wire, pos;
    cin >> wire >> pos;
    wire -= 1;
    if (wire == 0) {
      arr[wire + 1] = arr[wire] - pos;
      arr[wire] = 0;
    } else if (wire == n - 1) {
      arr[wire - 1] += pos - 1;
      arr[wire] = 0;
    } else {
      arr[wire - 1] += pos - 1;
      arr[wire + 1] += arr[wire] - pos;
      arr[wire] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << "\n";
  }
}
