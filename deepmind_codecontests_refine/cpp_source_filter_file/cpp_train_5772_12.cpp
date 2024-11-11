#include <bits/stdc++.h>
using namespace std;
int boo[20000 + 10][10 + 10];
int arr_emp[20000 + 10];
int arr_chat[2000 + 10];
int res[2000 + 10];
int main() {
  int n, m, k, tem1, tem2;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> boo[i][j];
    }
  }
  for (int u = 1; u <= k; u++) {
    cin >> tem1 >> tem2;
    arr_emp[tem1]++;
    arr_chat[tem2]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (boo[i][j] == 1) {
        res[i] += arr_chat[j];
      }
    }
    res[i] -= arr_emp[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}
