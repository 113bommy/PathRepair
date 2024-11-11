#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  bool ok = false;
  int cnt = 0;
  for (int i = 0; i < 2000; i++) {
    if (cnt == n) {
      ok = true;
      break;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        arr[i]++;
        int bb = arr[i] % n;
        if (bb == i) cnt++;
      } else {
        arr[i]--;
        if (arr[i] < 0) {
          int bb = arr[i] + n;
          if (bb == i) cnt++;
        } else {
          int bb = arr[i] % n;
          if (bb == i) cnt++;
        }
      }
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
