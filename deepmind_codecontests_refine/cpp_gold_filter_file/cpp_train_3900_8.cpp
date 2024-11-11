#include <bits/stdc++.h>
using namespace std;
long long ar[2005][2005];
long long arl[4010];
long long arr[4010];
long long ar1[2005][2005];
long long ar2[2005][2005];
long long far[2005][2005];
int vis[2005][2005];
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> ar[i][j];
  }
  int f = 1;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      int k = 1;
      int j = i;
      while (k <= i) {
        arl[f] += ar[k][j--];
        k++;
      }
    } else {
      int k = 1;
      int j = i - n;
      int j1 = n;
      while (k <= j) {
        arl[f] += ar[n - j + k][j1--];
        k++;
      }
    }
    f++;
  }
  int f1 = 1;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      int k = 1;
      int l = 1;
      while (k <= i) {
        arr[f1] += ar[n - i + k][l++];
        k++;
      }
    } else {
      int k = 1;
      int j = i - n;
      int l = 1;
      while (k <= j) {
        arr[f1] += ar[l++][n - j + k];
        k++;
      }
    }
    f1++;
  }
  int f2 = 1;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      int k = 1;
      int j = i;
      while (k <= i) {
        ar1[k][j--] = arl[f2];
        k++;
      }
    } else {
      int k = 1;
      int j = i - n;
      int j1 = n;
      while (k <= j) {
        ar1[n - j + k][j1--] = arl[f2];
        k++;
      }
    }
    f2++;
  }
  int f3 = 1;
  for (int i = 1; i <= 2 * n - 1; i++) {
    if (i <= n) {
      int k = 1;
      int l = 1;
      while (k <= i) {
        ar2[n - i + k][l++] = arr[f3];
        k++;
      }
    } else {
      int k = 1;
      int j = i - n;
      int l = 1;
      while (k <= j) {
        ar2[l++][n - j + k] = arr[f3];
        k++;
      }
    }
    f3++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      far[i][j] = ar1[i][j] + ar2[i][j] - ar[i][j];
    }
  }
  long long x = 0, y = 0;
  long long maxi = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (maxi <= far[i][j]) {
        maxi = far[i][j];
        x = i;
        y = j;
      }
    }
  }
  long long maxi2 = 0, x1 = 0, y1 = 0;
  if ((x + y) % 2 != 0) {
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 0) {
        for (int j = 2; j <= n; j += 2) {
          if (far[i][j] >= maxi2) {
            maxi2 = far[i][j];
            x1 = i;
            y1 = j;
          }
        }
      } else {
        for (int j = 1; j <= n; j += 2) {
          if (far[i][j] >= maxi2) {
            maxi2 = far[i][j];
            x1 = i;
            y1 = j;
          }
        }
      }
    }
  } else {
    for (int i = 1; i <= n; i++) {
      if (i % 2 != 0) {
        for (int j = 2; j <= n; j += 2) {
          if (far[i][j] >= maxi2) {
            maxi2 = far[i][j];
            x1 = i;
            y1 = j;
          }
        }
      } else {
        for (int j = 1; j <= n; j += 2) {
          if (far[i][j] >= maxi2) {
            maxi2 = far[i][j];
            x1 = i;
            y1 = j;
          }
        }
      }
    }
  }
  cout << maxi + maxi2 << endl;
  cout << x << " " << y << " " << x1 << " " << y1;
  return 0;
}
