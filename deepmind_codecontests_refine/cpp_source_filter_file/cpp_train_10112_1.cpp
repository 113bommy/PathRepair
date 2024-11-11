#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, ip, check = 1;
  bool flag = false;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) arr[i] = 0;
  for (int i = 0; i < m; ++i) {
    cin >> ip;
    arr[ip - 1]++;
    if (i >= n) {
      flag = false;
      for (int i = 0; i < n; ++i) {
        if (arr[i] < check) {
          flag = true;
          break;
        }
      }
      if (flag)
        cout << 0;
      else {
        cout << 1;
        check++;
      }
    } else
      cout << 0;
  }
  return 0;
}
