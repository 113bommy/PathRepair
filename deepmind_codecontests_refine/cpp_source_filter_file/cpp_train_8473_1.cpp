#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], a[8] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    a[arr[i]]++;
  }
  if (a[1] == n / 3 && a[2] + a[3] == n / 3 && a[4] + a[6] == n / 3 &&
      a[2] > a[4] && a[6] > a[3]) {
    while (a[4]--) {
      a[2]--;
      cout << "1 2 4" << endl;
    }
    while (a[2]--) cout << "1 2 6" << endl;
    while (a[3]--) cout << "1 3 6" << endl;
  } else
    cout << -1;
}
