#include <bits/stdc++.h>
using namespace std;
int a[400005];
int tmp[400005];
int number(int l, int r, int lim) {
  long long ret = 0;
  int ind = r - 1;
  for (int i = l; i < r - 1; ++i) {
    if (a[i] + a[r - 1] >= lim) {
      while (i < ind - 1) {
        if (a[i] + a[ind - 1] >= lim) {
          --ind;
        } else {
          break;
        }
      }
      int u = max(ind, i + 1);
      ret += r - 1 - u + 1;
    } else {
      continue;
    }
  }
  if (ret & 1) {
    return lim;
  } else {
    return 0;
  }
}
int getSolve(int n, int bit) {
  int ret = 0;
  int minL = n;
  for (int i = 0; i < n; ++i) {
    if (a[i] & (1 << bit)) {
      a[i] ^= (1 << bit);
      minL = min(minL, i);
    }
  }
  int k = minL - 1;
  long long num = 0;
  for (int i = minL; i < n; ++i) {
    if (a[i] + a[0] >= (1 << bit)) {
      break;
    }
    while (true) {
      if (a[k] + a[i] >= (1 << bit)) {
        --k;
      } else {
        break;
      }
    }
    num += k + 1;
  }
  ret ^= number(0, minL, (1 << bit));
  ret ^= number(minL, n, (1 << bit));
  if (num & 1) {
    ret ^= (1 << bit);
  }
  if (bit == 0) {
    return ret;
  }
  int pos = 0, r = minL;
  int ind = 0;
  while (pos < r && minL < n) {
    if (a[pos] < a[minL]) {
      tmp[ind++] = a[pos++];
    } else {
      tmp[ind++] = a[minL++];
    }
  }
  while (pos < r) {
    tmp[ind++] = a[pos++];
  }
  while (minL < n) {
    tmp[ind++] = a[minL++];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = tmp[i];
  }
  return ret ^ getSolve(n, bit - 1);
}
void solve() {
  int n;
  scanf("%d  ", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d ", &a[i]);
  }
  sort(a, a + n);
  printf("%d\n", getSolve(n, 23));
}
int main() {
  solve();
  return 0;
}
