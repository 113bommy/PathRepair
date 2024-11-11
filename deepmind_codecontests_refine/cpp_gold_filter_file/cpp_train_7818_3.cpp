#include <bits/stdc++.h>
using namespace std;
int mat[200][10000];
int main() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  int k = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    mat[a][k] = 1;
    mat[b][k] = 1;
    k++;
  }
  int maxi = 1e9 - 1;
  int cnt = 0;
  for (int i = 1; i < n + 1; i++) {
    cnt = 0;
    for (int j = 1; j < k; j++) {
      if (mat[i][j]) {
        cnt++;
      }
    }
    if (cnt == 0) {
      cout << "1" << endl;
      cout << i << " " << maxi << endl;
      maxi--;
    } else {
      cout << cnt << endl;
      for (int j = 1; j < k + 1; j++) {
        if (mat[i][j]) {
          cout << i << " " << j << endl;
        }
      }
    }
  }
}
