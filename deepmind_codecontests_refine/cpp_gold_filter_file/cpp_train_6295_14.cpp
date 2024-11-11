#include <bits/stdc++.h>
using namespace std;
int N;
int p[200005], q[200005];
int pp[200005], qp[200005];
int res[200005];
int ans[200005];
int BIT[200005];
void update(int x, int val) {
  while (x <= N) {
    BIT[x] += val;
    x += (x & (-x));
  }
}
int read(int x) {
  int sum = 0;
  while (x) {
    sum += BIT[x];
    x -= (x & (-x));
  }
  return sum;
}
int Find(int freq) {
  int ret, hi, lo, mid, ans;
  lo = 0, hi = N;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    int x = read(mid);
    if (x > freq) {
      hi = mid - 1;
    } else if (x < freq) {
      lo = mid + 1;
    } else if (x == freq) {
      ans = mid;
      lo = mid + 1;
    }
  }
  return ans;
}
int main() {
  int i;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d", &p[i]);
    p[i]++;
  }
  for (i = 1; i <= N; i++) {
    scanf("%d", &q[i]);
    q[i]++;
  }
  for (i = 0; i <= N; i++) BIT[i] = 0;
  for (i = 1; i <= N; i++) update(i, 1);
  for (i = 1; i < N; i++) {
    int x = read(p[i] - 1);
    pp[N - i] = x;
    update(p[i], -1);
  }
  for (i = 0; i <= N; i++) BIT[i] = 0;
  for (i = 1; i <= N; i++) update(i, 1);
  for (i = 1; i < N; i++) {
    int x = read(q[i] - 1);
    qp[N - i] = x;
    update(q[i], -1);
  }
  int carry = 0;
  for (i = 1; i < N; i++) {
    int x = pp[i] + qp[i] + carry;
    res[i] = x % (i + 1);
    carry = x / (i + 1);
  }
  for (i = 1; i <= N; i++) BIT[i] = 0;
  for (i = 1; i <= N; i++) update(i, 1);
  for (i = 1; i <= N; i++) {
    int x = res[N - i];
    int y = Find(x);
    if (i > 1) printf(" ");
    printf("%d", y);
    update(y + 1, -1);
  }
  printf("\n");
  return 0;
}
