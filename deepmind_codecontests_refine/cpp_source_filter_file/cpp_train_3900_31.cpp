#include <bits/stdc++.h>
using namespace std;
int i, j, k;
const int M = 2000 + 6;
long long a[M][M];
long long pref1[M][M], pref2[M][M];
long long valu[M][M];
void prnt(long long alu[M][M], int n) {
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << alu[i][j] << " ";
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cin >> a[i][j];
  }
  for (k = 1; k <= n; k++) {
    for (i = k, j = 1; i <= n and j <= n; i++, j++) {
      pref1[i][j] = a[i][j] + pref1[i - 1][j - 1];
    }
  }
  for (k = 2; k <= n; k++) {
    for (i = 1, j = k; i <= n and j <= n; i++, j++) {
      pref1[i][j] = a[i][j] + pref1[i - 1][j - 1];
    }
  }
  for (k = n; k >= 1; k--) {
    for (i = 1, j = k; i <= n and j >= 1; i++, j--) {
      pref2[i][j] = a[i][j] + pref2[i - 1][j + 1];
    }
  }
  for (k = 2; k <= n; k++) {
    for (i = k, j = n; i <= n and j >= 1; i++, j--) {
      pref2[i][j] = a[i][j] + pref2[i - 1][j + 1];
    }
  }
  int edge = n;
  for (k = 1; k <= n; k++) {
    for (i = k, j = 1; i <= n and j <= n; i++, j++) {
      valu[i][j] += pref1[n][edge] - a[i][j];
    }
    edge--;
  }
  edge = n - 1;
  for (k = 2; k <= n; k++) {
    for (i = 1, j = k; i <= n and j <= n; i++, j++) {
      valu[i][j] += pref1[edge][n] - a[i][j];
    }
    edge--;
  }
  edge = n;
  for (k = n; k >= 1; k--) {
    for (i = 1, j = k; i <= n and j >= 1; i++, j--) {
      valu[i][j] += pref2[edge][1];
    }
    edge--;
  }
  edge = 2;
  for (k = 2; k <= n; k++) {
    for (i = k, j = n; i <= n and j >= 1; i++, j--) {
      valu[i][j] += pref2[n][edge];
    }
    edge++;
  }
  long long sum1 = 0, sum2 = 0;
  int x1, y1, x2, y2;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if ((i + j) % 2) continue;
      if (valu[i][j] > sum1) {
        x1 = i, y1 = j;
        sum1 = valu[i][j];
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if ((i + j) % 2 == 0) continue;
      if (valu[i][j] > sum2) {
        x2 = i, y2 = j;
        sum2 = valu[i][j];
      }
    }
  }
  cout << sum1 + sum2 << "\n";
  cout << x1 << " " << y1 << " " << x2 << " " << y2;
}
