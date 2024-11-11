#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (1); i <= (b); i++) {
    multiply *= a;
  }
  return multiply;
}
inline long long ABS(long long a) { return (a >= 0) ? a : -a; }
int n, c, in, l;
vector<int> st[500003];
int tree[3000001], prop[3000001];
void update(int node, int b, int e, int i, int j, int val) {
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    tree[node] += (e - b + 1) * val;
    prop[node] += val;
    return;
  }
  int left = 2 * node, right = 2 * node + 1, mid = (b + e) / 2;
  update(left, b, mid, i, j, val);
  update(right, mid + 1, e, i, j, val);
  tree[node] = tree[left] + tree[right] + (e - b + 1) * prop[node];
  return;
}
int query(int node, int b, int e, int i, int j, int carry) {
  if (b > j || e < i) return 0;
  if (b >= i && e <= j) return tree[node] + carry * (e - b + 1);
  int left = 2 * node, right = 2 * node + 1, mid = (b + e) / 2;
  int p1, p2;
  p1 = query(left, b, mid, i, j, carry + prop[node]);
  p2 = query(right, mid + 1, e, i, j, carry + prop[node]);
  return p1 + p2;
}
int main() {
  scanf("%d %d", &n, &c);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &l);
    for (int j = (1); j <= (l); j++) {
      scanf("%d", &in);
      st[i].push_back(in);
    }
  }
  memset(tree, 0, sizeof(tree));
  memset(prop, 0, sizeof(prop));
  bool flag = 1;
  for (int i = (1); i <= (n - 1); i++) {
    bool flag1 = 0;
    for (int j = (0); j <= (min(st[i].size() - 1, st[i + 1].size() - 1)); j++) {
      if (st[i][j] != st[i + 1][j]) {
        flag1 = 1;
        if (st[i][j] < st[i + 1][j]) {
          update(1, 1, c, c - st[i + 1][j] + 2, c - st[i][j] + 1, 1);
        } else {
          update(1, 1, c, 1, c - st[i][j] + 1, 1);
          update(1, 1, c, c - st[i + 1][j] + 2, c, 1);
        }
        break;
      }
    }
    if (flag1 == 0) {
      if (st[i].size() > st[i + 1].size()) {
        flag = 0;
        break;
      }
    }
  }
  if (flag == 1) {
    for (int i = (1); i <= (c); i++) {
      if (!query(1, 1, c, i, i, 0)) {
        printf("%d\n", i - 1);
        return 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}
