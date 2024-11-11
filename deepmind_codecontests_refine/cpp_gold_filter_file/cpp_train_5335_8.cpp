#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int l = 1, r = n - 1;
    int a = arr[0];
    int b = 0;
    int tot_a = a, tot_b = 0;
    int flag = 1;
    int moves = 1;
    while (l <= r) {
      if (flag == 1) {
        moves++;
        b = 0;
        while (b <= a) {
          b += arr[r];
          r--;
          if (r < l) {
            break;
          }
        }
        tot_b += b;
        flag = 0;
      } else {
        moves++;
        a = 0;
        while (a <= b) {
          a += arr[l];
          l++;
          if (l > r) {
            break;
          }
        }
        tot_a += a;
        flag = 1;
      }
    }
    cout << moves << " " << tot_a << " " << tot_b << endl;
  }
}
