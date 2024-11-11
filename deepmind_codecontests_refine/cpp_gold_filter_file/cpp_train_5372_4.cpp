#include <bits/stdc++.h>
using namespace std;
int n, m;
const int Max = 1e6;
long long Arr[Max];
long long Pos[Max * 2];
void Build(int rt, int l, int r) {
  if (l == r) {
    Pos[rt] = Arr[l] % m;
    return;
  }
  int mid = (l + r) / 2;
  Build(rt * 2, l, mid);
  Build(rt * 2 + 1, mid + 1, r);
  Pos[rt] = (Pos[rt * 2] * Pos[rt * 2 + 1]) % m;
}
long long query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) {
    return Pos[rt];
  }
  long long ans = 1;
  int mid = (l + r) / 2;
  if (mid >= L) {
    ans *= query(L, R, l, mid, rt * 2) % m;
  }
  if (mid < R) {
    ans *= query(L, R, mid + 1, r, rt * 2 + 1) % m;
  }
  return ans % m;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &Arr[i]);
  }
  Build(1, 1, n);
  long long Sum = 0;
  for (int i = 1; i <= n; i++) {
    int l = i;
    int r = n;
    int pos = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (query(i, mid, 1, n, 1) % m == 0) {
        pos = mid;
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (query(i, pos, 1, n, 1) % m == 0) {
      Sum += (n - pos + 1);
    }
  }
  printf("%lld\n", Sum);
  return 0;
}
