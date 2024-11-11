#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int bitA[N], bitB[N], arrA[N], arrB[N];
void update(int bit[], int pos, int val) {
  for (; pos < N; pos += pos & -pos) bit[pos] += val;
}
int query(int bit[], int pos) {
  int ans = 0;
  for (; pos; pos -= pos & -pos) ans += bit[pos];
  return ans;
}
int main() {
  int n, k, q, A, B;
  scanf("%d %d %d %d %d", &n, &k, &A, &B, &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int d, a;
      scanf("%d %d", &d, &a);
      int x = min(arrA[d] + a, A) - arrA[d];
      update(bitA, d, x);
      arrA[d] += x;
      x = min(arrB[d] + a, B) - arrB[d];
      update(bitB, d, x);
      arrB[d] += x;
    } else {
      int p;
      scanf("%d", &p);
      int ans = query(bitB, p - 1) + query(bitA, n) - query(bitA, p + k - 1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
