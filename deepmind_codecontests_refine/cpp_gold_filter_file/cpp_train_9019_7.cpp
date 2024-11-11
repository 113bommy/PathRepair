#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[6][6];
  memset(arr, 0, sizeof arr);
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = arr[b][a] = 1;
  }
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 6; j++) {
      for (int k = 1; k < 6; k++) {
        if (i == j || i == k || j == k) continue;
        if ((arr[i][j] + arr[i][k] + arr[j][k]) % 3 == 0) {
          puts("WIN");
          return 0;
        }
      }
    }
  }
  puts("FAIL");
}
