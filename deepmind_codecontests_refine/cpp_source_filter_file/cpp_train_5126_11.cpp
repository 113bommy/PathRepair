#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, cnt = 0, flag = 0;
    cin >> n >> x;
    int arr[n], a[102];
    for (int i = 0; i < 102; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      a[arr[i]]++;
    }
    for (int i = 1; i < 102; i++) {
      if (a[i] == 0 && x != 0) {
        x--;
        a[i]++;
      }
    }
    for (int i = 1; i < 102; i++) {
      if (i == 101)
        cout << i + x << endl;
      else if (a[i] == 0) {
        cout << i - 1 + x << endl;
        break;
      }
    }
  }
}
