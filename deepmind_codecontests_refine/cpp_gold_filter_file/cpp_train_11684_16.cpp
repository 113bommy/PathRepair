#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      if (arr[i] % 2 == 0) {
        cout << "1\n";
        cout << i + 1 << "\n";
        flag = true;
        break;
      } else {
        if (i > 0) {
          cout << "2\n";
          cout << i << " " << i + 1 << "\n";
          flag = true;
          break;
        }
      }
    }
    if (flag == false) cout << "-1\n";
  }
  return 0;
}
