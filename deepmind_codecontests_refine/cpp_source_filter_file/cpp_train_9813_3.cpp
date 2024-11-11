#include <bits/stdc++.h>
using namespace std;
int id[100005], bit[100005];
pair<int, int> A[2 * 100005];
int n;
int Q(int x) {
  int r = 0;
  for (; x; x -= x & -x) r += bit[x];
  return x;
}
void U(int x, int v) {
  for (; x < 100005; x += x & -x) bit[x] += v;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, j = 0; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    A[j++] = make_pair(x, i);
    A[j++] = make_pair(y, -i);
  }
  sort(A, A + 2 * n);
  int ans = 0;
  for (int i = 0, k = 1; i < 2 * n; i++) {
    if (A[i].second > 0) {
      id[A[i].second] = k;
      U(k++, 1);
    } else {
      if (Q(id[-A[i].second] - 1)) ans++;
      U(id[-A[i].second], -1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
