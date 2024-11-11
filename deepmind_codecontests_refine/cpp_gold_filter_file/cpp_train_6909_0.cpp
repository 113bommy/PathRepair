#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
long long int a[maxn], L[maxn], R[maxn], leftx[maxn], rightx[maxn];
long long int mini, ja;
int main() {
  mini = 100000000000;
  ja = -1;
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    L[i] = mini;
    if (a[i] < mini) {
      mini = a[i];
      ja = i;
    }
  }
  ja = -1;
  mini = 100000000000;
  for (int i = n; i >= 1; i--) {
    R[i] = mini;
    if (a[i] < mini) {
      mini = a[i];
      ja = i;
    }
  }
  ja = -1;
  mini = 100000000000;
  for (int i = x; i >= 1; i--) {
    leftx[i] = mini;
    if (a[i] < mini) {
      mini = a[i];
      ja = i;
    }
  }
  ja = -1;
  mini = 100000000000;
  for (int i = x + 1; i <= n; i++) {
    rightx[i] = mini;
    if (a[i] < mini) {
      mini = a[i];
      ja = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == x and L[i] >= a[i] and R[i] >= a[i]) {
      for (int j = 1; j <= n; j++) {
        if (j == i)
          cout << n * a[j] << " ";
        else
          cout << a[j] - a[i] << " ";
      }
      return 0;
    }
    if (i < x and L[i] >= a[i] and leftx[i] > a[i] and R[x] >= a[i]) {
      for (int j = 1; j <= n; j++) {
        if (j < i or j > x) cout << a[j] - a[i] << " ";
        if (j == i) cout << a[i] * n + x - i << " ";
        if (j > i and j <= x) cout << a[j] - a[i] - 1 << " ";
      }
      return 0;
    }
    if (i > x and R[i] > a[i] and rightx[i] >= a[i] and L[x] > a[i] and
        a[x] > a[i]) {
      for (int j = 1; j <= n; j++) {
        if (j <= x) cout << a[j] - a[i] - 1 << " ";
        if (j > x and j < i) cout << a[j] - a[i] << " ";
        if (j == i) cout << (a[j] + 1) * n - (i - x) << " ";
        if (j > i) cout << a[j] - a[i] - 1 << " ";
      }
      return 0;
    }
  }
}
