#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-9;
int a[100100];
int tree[4 * 100100];
int N, x;
void buildTree(int v = 1, int tl = 0, int tr = N - 1) {
  if (tl == tr) {
    tree[v] = a[tl];
  } else {
    int tm = (tl + tr) >> 1;
    buildTree(v << 1, tl, tm);
    buildTree(v << 1 | 1, tm + 1, tr);
    tree[v] = min(tree[v << 1], tree[v << 1 | 1]);
  }
}
int getMin(int l, int r, int v = 1, int tl = 0, int tr = N - 1) {
  if (r < l) {
    return INF;
  }
  if (l == tl && r == tr) {
    return tree[v];
  }
  int tm = (tl + tr) >> 1;
  if (r <= tm) {
    return getMin(l, r, v << 1, tl, tm);
  }
  if (l > tm) {
    return getMin(l, r, v << 1 | 1, tm + 1, tr);
  }
  return min(getMin(l, tm, v << 1, tl, tm),
             getMin(tm + 1, r, v << 1 | 1, tm + 1, tr));
}
int main() {
  scanf("%d%d", &N, &x);
  --x;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
  }
  buildTree();
  for (int i = 0; i < N; ++i) {
    long long tmp = 1LL * a[i] * N;
    if (x > i) {
      tmp += x - i;
    } else if (x < i) {
      tmp += N - i + x;
    }
    if (i == x) {
      if (getMin(0, i - 1) >= a[i] && getMin(i + 1, N - 1) >= a[i]) {
        for (int j = 0; j < N; ++j)
          if (j == x) {
            printf("%I64d ", tmp);
          } else {
            printf("%d ", a[j] - a[i]);
          }
        return 0;
      }
    } else if (x > i) {
      if (getMin(0, i - 1) >= a[i] && getMin(i + 1, x) >= a[i] + 1 &&
          getMin(x + 1, N - 1) >= a[i]) {
        for (int j = 0; j < N; ++j)
          if (j == i) {
            printf("%I64d ", tmp);
          } else if (j > i && j <= x) {
            printf("%d ", a[j] - a[i] - 1);
          } else {
            printf("%d ", a[j] - a[i]);
          }
        return 0;
      }
    } else {
      if (getMin(0, x) >= a[i] + 1 && getMin(x + 1, i - 1) >= a[i] &&
          getMin(i + 1, N - 1) >= a[i] + 1) {
        for (int j = 0; j < N; ++j)
          if (j == i) {
            printf("%I64d ", tmp);
          } else if (j <= x || j > i) {
            printf("%d ", a[j] - a[i] - 1);
          } else {
            printf("%d ", a[j] - a[i]);
          }
        return 0;
      }
    }
  }
  return 0;
}
