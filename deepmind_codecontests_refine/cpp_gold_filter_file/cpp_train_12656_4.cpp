#include <bits/stdc++.h>
using namespace std;
int sum[400005];
int seg[400005];
int ar[100005];
int n;
void upd(int in) {
  sum[in] = sum[2 * in + 1] + sum[2 * in];
  int v = seg[2 * in + 1];
  if (v > 0) {
    seg[in] = v;
    seg[in] = max(seg[in], sum[2 * in + 1] + seg[2 * in]);
  } else {
    seg[in] = sum[2 * in + 1] + seg[2 * in];
  }
  if (in != 1) upd(in / 2);
}
void lazy(int in, int no, int left, int right, int tar) {
  if (left == right && left == tar) {
    sum[in] = no;
    seg[in] = no;
    upd(in / 2);
    return;
  }
  int m = (left + right) / 2;
  if (tar <= m) {
    lazy(2 * in, no, left, m, tar);
  } else {
    lazy(2 * in + 1, no, m + 1, right, tar);
  }
}
int quer(int in, int left, int right, int v) {
  if (seg[in] <= 0) return -1;
  if (left == right) return ar[left];
  if (seg[2 * in + 1] + v > 0)
    return quer(2 * in + 1, (left + right) / 2 + 1, right, v);
  return quer(2 * in, left, (left + right) / 2, sum[2 * in + 1] + v);
}
int main() {
  scanf("%d", &n);
  int ord, cm, no;
  if (n == 1) {
    int v1, v2, v3;
    cin >> v1 >> v2;
    if (v2 == 0)
      cout << -1;
    else {
      cin >> v3;
      cout << v3;
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &ord, &cm);
    if (cm == 1) {
      scanf("%d", &no);
      lazy(1, 1, 1, n, ord);
      ar[ord] = no;
    } else {
      lazy(1, -1, 1, n, ord);
    }
    cout << quer(1, 1, n, 0) << endl;
  }
  return 0;
}
