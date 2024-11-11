#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 1LL;
const int inf = 1e9 + 1e8;
const double PI = acos(-1.0);
const int N = 1e5 + 100;
int tree[N * 30][2], data[N * 3][2];
int a[N * 3], p[N * 3], n, tot = 1, root = 1;
void Insert(int x) {
  int now = root, num[31];
  for (int i = 30; i >= 0; --i) {
    num[i] = x & 1;
    x >>= 1;
  }
  for (int i = 0; i <= 30; ++i) {
    int t = num[i];
    if (tree[now][t])
      data[now][t]++;
    else {
      tree[now][t] = ++tot;
      data[now][t] = 1;
    }
    now = tree[now][t];
  }
}
void del(int x) {
  int now = root, num[31];
  for (int i = 30; i >= 0; --i) {
    num[i] = x & 1;
    x >>= 1;
  }
  for (int i = 0; i <= 30; ++i) {
    int t = num[i];
    data[now][t]--;
    now = tree[now][t];
    if (!data[now][t]) tree[now][t] = 0;
  }
}
int finds(int x) {
  int now = root, r = 1, ret = 0;
  int num[31];
  for (int i = 30; i >= 0; --i) {
    num[i] = x & 1;
    x >>= 1;
  }
  for (int i = 0; i <= 30; ++i) {
    int t = num[i];
    if (data[now][t]) {
      ret *= 2;
      ret += t;
      now = tree[now][t];
    } else {
      ret *= 2;
      ret += t ^ 1;
      now = tree[now][t ^ 1];
    }
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    Insert(p[i]);
  }
  for (int i = 1; i <= n; ++i) {
    int x = finds(a[i]);
    del(x);
    printf("%d ", x ^ a[i]);
  }
  return 0;
}
