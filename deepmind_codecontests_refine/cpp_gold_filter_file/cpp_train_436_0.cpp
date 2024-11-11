#include <bits/stdc++.h>
int nTest;
int n;
int a[100007];
int min(int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int main() {
  scanf("%d", &nTest);
  for (int iTest = 1; iTest <= nTest; ++iTest) {
    scanf("%d", &n);
    int maxVal = 0;
    int minVal = 1e9;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == -1) {
        if (i == 1) {
          if (a[i + 1] >= 0) {
            minVal = min(a[i + 1], minVal);
            maxVal = max(a[i + 1], maxVal);
          }
        } else if (i == n) {
          if (a[i - 1] >= 0) {
            minVal = min(a[i - 1], minVal);
            maxVal = max(a[i - 1], maxVal);
          }
        } else {
          if (a[i - 1] >= 0) {
            minVal = min(a[i - 1], minVal);
            maxVal = max(a[i - 1], maxVal);
          }
          if (a[i + 1] >= 0) {
            minVal = min(a[i + 1], minVal);
            maxVal = max(a[i + 1], maxVal);
          }
        }
      }
    }
    int maxDist = 0;
    int res = (maxVal + minVal) / 2;
    for (int i = 1; i < n; ++i) {
      int cur = a[i];
      int next = a[i + 1];
      if (cur == -1) {
        cur = res;
      }
      if (next == -1) {
        next = res;
      }
      maxDist = max(abs(cur - next), maxDist);
    }
    printf("%d %d\n", maxDist, res);
  }
  return 0;
}
