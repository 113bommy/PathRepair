#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct mtx {
  int a[2][2];
  mtx operator*(const mtx tmp) {
    mtx as;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++) as.a[i][j] = 1e9;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 1; j++)
        for (int k = 0; k <= 1; k++)
          as.a[i][j] = min(as.a[i][j], a[i][k] + tmp.a[k][j]);
    return as;
  }
} sum1[N << 2][4], sum2[N << 2][4];
int n, m, q, num[5], dp[N][2];
int ans1, ans2, sum[N << 1], x, y, kp;
int sun1[N << 2][2], sun2[N << 2][2];
bool w[3][N], k[3][N], lz1[N << 2][2], lz2[N << 2][2];
char ch;
void bui1(int o, int l, int r) {
  if (l == r) {
    sum1[o][0] = (mtx){w[1][l] + w[2][l], !w[1][l] + !w[2][l] + m,
                       w[1][l] + w[2][l] + m, !w[1][l] + !w[2][l]};
    sum1[o][1] = (mtx){!w[1][l] + w[2][l], w[1][l] + !w[2][l] + m,
                       !w[1][l] + w[2][l] + m, w[1][l] + !w[2][l]};
    sum1[o][2] = (mtx){w[1][l] + !w[2][l], !w[1][l] + w[2][l] + m,
                       w[1][l] + !w[2][l] + m, !w[1][l] + w[2][l]};
    sum1[o][3] = (mtx){!w[1][l] + !w[2][l], w[1][l] + w[2][l] + m,
                       !w[1][l] + !w[2][l] + m, w[1][l] + w[2][l]};
    sun1[o][0] = w[1][l];
    sun1[o][1] = w[2][l];
    return;
  }
  int mid = l + r >> 1;
  bui1(o << 1, l, mid);
  bui1(o << 1 | 1, mid + 1, r);
  sum1[o][0] = sum1[o << 1][0] * sum1[o << 1 | 1][0];
  sum1[o][1] = sum1[o << 1][1] * sum1[o << 1 | 1][1];
  sum1[o][2] = sum1[o << 1][2] * sum1[o << 1 | 1][2];
  sum1[o][3] = sum1[o << 1][3] * sum1[o << 1 | 1][3];
  sun1[o][0] = sun1[o << 1][0] + sun1[o << 1 | 1][0];
  sun1[o][1] = sun1[o << 1][1] + sun1[o << 1 | 1][1];
}
void bui2(int o, int l, int r) {
  if (l == r) {
    sum2[o][0] = (mtx){k[1][l] + k[2][l], !k[1][l] + !k[2][l] + n,
                       k[1][l] + k[2][l] + n, !k[1][l] + !k[2][l]};
    sum2[o][1] = (mtx){!k[1][l] + k[2][l], k[1][l] + !k[2][l] + n,
                       !k[1][l] + k[2][l] + n, k[1][l] + !k[2][l]};
    sum2[o][2] = (mtx){k[1][l] + !k[2][l], !k[1][l] + k[2][l] + n,
                       k[1][l] + !k[2][l] + n, !k[1][l] + k[2][l]};
    sum2[o][3] = (mtx){!k[1][l] + !k[2][l], k[1][l] + k[2][l] + n,
                       !k[1][l] + !k[2][l] + n, k[1][l] + k[2][l]};
    sun2[o][0] = k[1][l];
    sun2[o][1] = k[2][l];
    return;
  }
  int mid = l + r >> 1;
  bui2(o << 1, l, mid);
  bui2(o << 1 | 1, mid + 1, r);
  sum2[o][0] = sum2[o << 1][0] * sum2[o << 1 | 1][0];
  sum2[o][1] = sum2[o << 1][1] * sum2[o << 1 | 1][1];
  sum2[o][2] = sum2[o << 1][2] * sum2[o << 1 | 1][2];
  sum2[o][3] = sum2[o << 1][3] * sum2[o << 1 | 1][3];
  sun2[o][0] = sun2[o << 1][0] + sun2[o << 1 | 1][0];
  sun2[o][1] = sun2[o << 1][1] + sun2[o << 1 | 1][1];
}
void push1(int o, int l, int r) {
  if (lz1[o][0]) {
    int mid = l + r >> 1;
    lz1[o << 1][0] ^= 1;
    lz1[o << 1 | 1][0] ^= 1;
    swap(sum1[o << 1][0], sum1[o << 1][1]);
    swap(sum1[o << 1][2], sum1[o << 1][3]);
    swap(sum1[o << 1 | 1][0], sum1[o << 1 | 1][1]);
    swap(sum1[o << 1 | 1][2], sum1[o << 1 | 1][3]);
    sun1[o << 1][0] = mid - l + 1 - sun1[o << 1][0];
    sun1[o << 1 | 1][0] = r - mid - sun1[o << 1 | 1][0];
    lz1[o][0] = 0;
  }
  if (lz1[o][1]) {
    int mid = l + r >> 1;
    lz1[o << 1][1] ^= 1;
    lz1[o << 1 | 1][1] ^= 1;
    swap(sum1[o << 1][0], sum1[o << 1][2]);
    swap(sum1[o << 1][1], sum1[o << 1][3]);
    swap(sum1[o << 1 | 1][0], sum1[o << 1 | 1][1]);
    swap(sum1[o << 1 | 1][2], sum1[o << 1 | 1][3]);
    sun1[o << 1][1] = mid - l + 1 - sun1[o << 1][1];
    sun1[o << 1 | 1][1] = r - mid - sun1[o << 1 | 1][1];
    lz1[o][1] = 0;
  }
}
void push2(int o, int l, int r) {
  if (lz2[o][0]) {
    int mid = l + r >> 1;
    lz2[o << 1][0] ^= 1;
    lz2[o << 1 | 1][0] ^= 1;
    swap(sum2[o << 1][0], sum2[o << 1][1]);
    swap(sum2[o << 1][2], sum2[o << 1][3]);
    swap(sum2[o << 1 | 1][0], sum2[o << 1 | 1][1]);
    swap(sum2[o << 1 | 1][2], sum2[o << 1 | 1][3]);
    sun2[o << 1][0] = mid - l + 1 - sun2[o << 1][0];
    sun2[o << 1 | 1][0] = r - mid - sun2[o << 1 | 1][0];
    lz2[o][0] = 0;
  }
  if (lz2[o][1]) {
    int mid = l + r >> 1;
    lz2[o << 1][1] ^= 1;
    lz2[o << 1 | 1][1] ^= 1;
    swap(sum2[o << 1][0], sum2[o << 1][2]);
    swap(sum2[o << 1][1], sum2[o << 1][3]);
    swap(sum2[o << 1 | 1][0], sum2[o << 1 | 1][1]);
    swap(sum2[o << 1 | 1][2], sum2[o << 1 | 1][3]);
    sun2[o << 1][1] = mid - l + 1 - sun2[o << 1][1];
    sun2[o << 1 | 1][1] = r - mid - sun2[o << 1 | 1][1];
    lz2[o][1] = 0;
  }
}
void modi1(int o, int l, int r) {
  if (x <= l && r <= y) {
    lz1[o][kp] ^= 1;
    sun1[o][kp] = r - l + 1 - sun1[o][kp];
    if (!kp) {
      swap(sum1[o][0], sum1[o][1]);
      swap(sum1[o][2], sum1[o][3]);
    } else {
      swap(sum1[o][0], sum1[o][2]);
      swap(sum1[o][1], sum1[o][3]);
    }
    return;
  }
  push1(o, l, r);
  int mid = l + r >> 1;
  if (x <= mid) modi1(o << 1, l, mid);
  if (y > mid) modi1(o << 1 | 1, mid + 1, r);
  sum1[o][0] = sum1[o << 1][0] * sum1[o << 1 | 1][0];
  sum1[o][1] = sum1[o << 1][1] * sum1[o << 1 | 1][1];
  sum1[o][2] = sum1[o << 1][2] * sum1[o << 1 | 1][2];
  sum1[o][3] = sum1[o << 1][3] * sum1[o << 1 | 1][3];
  sun1[o][0] = sun1[o << 1][0] + sun1[o << 1 | 1][0];
  sun1[o][1] = sun1[o << 1][1] + sun1[o << 1 | 1][1];
}
void modi2(int o, int l, int r) {
  if (x <= l && r <= y) {
    lz2[o][kp] ^= 1;
    sun2[o][kp] = r - l + 1 - sun2[o][kp];
    if (!kp) {
      swap(sum2[o][0], sum2[o][1]);
      swap(sum2[o][2], sum2[o][3]);
    } else {
      swap(sum2[o][0], sum2[o][2]);
      swap(sum2[o][1], sum2[o][3]);
    }
    return;
  }
  push2(o, l, r);
  int mid = l + r >> 1;
  if (x <= mid) modi2(o << 1, l, mid);
  if (y > mid) modi2(o << 1 | 1, mid + 1, r);
  sum2[o][0] = sum2[o << 1][0] * sum2[o << 1 | 1][0];
  sum2[o][1] = sum2[o << 1][1] * sum2[o << 1 | 1][1];
  sum2[o][2] = sum2[o << 1][2] * sum2[o << 1 | 1][2];
  sum2[o][3] = sum2[o << 1][3] * sum2[o << 1 | 1][3];
  sun2[o][0] = sun2[o << 1][0] + sun2[o << 1 | 1][0];
  sun2[o][1] = sun2[o << 1][1] + sun2[o << 1 | 1][1];
}
void gta() {
  ans1 = min(sun1[1][0] + sum2[1][0].a[0][0],
             n - sun1[1][0] + sum2[1][0].a[1][0]) +
         sun1[1][1];
  ans1 = min(ans1, min(sun1[1][0] + sum2[1][0].a[0][1],
                       n - sun1[1][0] + sum2[1][0].a[1][1]) +
                       n - sun1[1][1]);
  ans2 = min(sun2[1][0] + sum1[1][0].a[0][0],
             m - sun2[1][0] + sum1[1][0].a[1][0]) +
         sun2[1][1];
  ans2 = min(ans2, min(sun2[1][0] + sum1[1][0].a[0][1],
                       m - sun2[1][0] + sum1[1][0].a[1][1]) +
                       m - sun2[1][1]);
  printf("%d\n", min(ans1, ans2));
}
int main() {
  scanf("%d %d %d\n", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    ch = getchar();
    if (ch == 'B') w[1][i] = 1;
  }
  getchar();
  for (int i = 1; i <= n; i++) {
    ch = getchar();
    if (ch == 'B') w[2][i] = 1;
  }
  getchar();
  for (int i = 1; i <= m; i++) {
    ch = getchar();
    if (ch == 'B') k[1][i] = 1;
  }
  getchar();
  for (int i = 1; i <= m; i++) {
    ch = getchar();
    if (ch == 'B') k[2][i] = 1;
  }
  getchar();
  bui1(1, 1, n);
  bui2(1, 1, m);
  gta();
  for (int i = 1; i <= q; i++) {
    ch = getchar();
    scanf(" %d %d", &x, &y);
    getchar();
    if (ch == 'L') {
      kp = 0;
      modi1(1, 1, n);
    } else if (ch == 'R') {
      kp = 1;
      modi1(1, 1, n);
    } else if (ch == 'U') {
      kp = 0;
      modi2(1, 1, m);
    } else {
      kp = 1;
      modi2(1, 1, m);
    }
    gta();
  }
}
