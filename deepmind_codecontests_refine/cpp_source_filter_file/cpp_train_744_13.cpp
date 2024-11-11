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
    int flag = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n == 1) {
      cout << "YES\n";
      continue;
    }
    if (arr[0] + 1 == arr[1]) {
      for (int i = 1; i < n; i++)
        if (arr[i] != (arr[i - 1] % n + 1)) {
          flag = 1;
          break;
        }
    } else {
      for (int i = 1; i < n; i++) {
        if ((arr[i]) % n + 1 != arr[i - 1]) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
