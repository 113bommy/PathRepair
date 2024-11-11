#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
long long arr[N];
int main() {
  ios_base::sync_with_stdio(), cout.tie(NULL), cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    if (n % 2 == 1) {
      cout << arr[n / 2];
      int x = n / 2 - 1;
      int y = n / 2 + 1;
      while (x >= 0) {
        cout << arr[y++] << " " << arr[x--] << " ";
      }
      cout << endl;
    } else {
      int x = n / 2 - 1;
      int y = n / 2;
      while (x >= 0) {
        cout << arr[y++] << " " << arr[x--] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
