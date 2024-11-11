#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  int n, l, r;
  cin >> n >> l >> r;
  int arr1[n];
  int arr2[n];
  int a[r - l];
  int b[r - l];
  int index = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
    if (i + 1 >= l && i + 1 <= r) {
      a[index] = arr1[i];
      index++;
    }
  }
  index = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
    if (i + 1 >= l && i + 1 <= r) {
      b[index] = arr2[i];
      index++;
    }
  }
  sort(a, a + (r - l) + 1);
  sort(b, b + (r - l) + 1);
  for (int i = 0; i <= (r - l); i++) {
    if (a[i] != b[i]) {
      cout << "LIE" << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i + 1 < l || i + 1 > r) {
      if (arr1[i] != arr2[i]) {
        cout << "LTE" << endl;
        return 0;
      }
    }
  }
  cout << "TRUTH" << endl;
  return 0;
}
