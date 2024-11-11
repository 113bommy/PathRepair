#include <bits/stdc++.h>
using namespace std;
void print(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  cin >> t;
  int arr[305][305];
  int flag = 1;
  while (t--) {
    flag = 1;
    int n, m;
    cin >> n >> m;
    int i, j;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &(arr[i][j]));
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (arr[i][j] > 4) {
          flag = 0;
          break;
        } else if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) {
          if (arr[i][j] > 2) {
            flag = 0;
            break;
          }
        } else if ((i == 0 || i == n - 1) || (j == 0 || j == n - 1)) {
          if (arr[i][j] > 3) {
            flag = 0;
            break;
          }
        }
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if ((i == 0 || i == n - 1) && (j == 0 || j == n - 1)) {
          arr[i][j] = 2;
        } else if ((i == 0 || i == n - 1) || (j == 0 || j == n - 1)) {
          arr[i][j] = 3;
        } else {
          arr[i][j] = 4;
        }
      }
    }
    if (flag == 0) {
      printf("NO\n");
    } else if (flag == 1) {
      printf("YES\n");
      for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
          printf("%d ", (arr[i][j]));
        }
        printf("\n");
      }
    }
  }
  return 0;
}
