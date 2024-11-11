#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005 * 6;
struct elem {
  long long I, L, R;
  elem(long long cI = 0, long long cL = 0, long long cR = 0) {
    I = cI;
    L = cL;
    R = cR;
  }
} A[100005], B[100005];
long long C[maxn], ge;
struct Itree {
  long long val[100000 * 30];
  long long cL, cR, ans, loc;
  void build(int L, int R, int o) {
    if (L == R) {
      val[o] = 1;
      return;
    }
    int mid = (L + R) >> 1;
    build(L, mid, o * 2);
    build(mid + 1, R, o * 2 + 1);
    val[o] = val[o * 2] + val[o * 2 + 1];
  }
  void update(int L, int R, int o) {
    if (cL <= L && R <= cR) {
      val[o] = 0;
      return;
    }
    if (val[o] == 0) return;
    int mid = (L + R) >> 1;
    if (cL <= mid) update(L, mid, o * 2);
    if (cR > mid) update(mid + 1, R, o * 2 + 1);
    val[o] = val[o * 2] + val[o * 2 + 1];
  }
  void query(int L, int R, int o) {
    if (L == R) {
      if (val[o] != 0) {
        loc = L;
        ans += val[o];
      }
      return;
    }
    int mid = (L + R) >> 1;
    if (val[o] == 0) {
      val[o * 2] = val[o * 2 + 1] = 0;
    }
    if (cL <= mid) query(L, mid, o * 2);
    if (cR > mid) query(mid + 1, R, o * 2 + 1);
  }
} T;
int h, q;
void add(long long d) {
  C[ge++] = d;
  if ((d + 1) <= ((1LL << h) - 1)) {
    C[ge++] = d + 1;
  }
  if (d - 1 >= (1LL << (h - 1))) {
    C[ge++] = d - 1;
  }
}
int main() {
  int c0 = 0, c1 = 0;
  scanf("%d%d", &h, &q);
  for (int i = 0; i < q; i++) {
    long long I, L, R, ans;
    scanf("%I64d%I64d%I64d%I64d", &I, &L, &R, &ans);
    while ((L * 2LL) < (1LL << h)) {
      L = (L * 2);
    }
    while ((R * 2LL + 1) < (1LL << h)) {
      R = (R * 2) + 1;
    }
    if (L > R) swap(L, R);
    if (ans == 0) {
      A[c0++] = elem(I, L, R);
    } else {
      B[c1++] = elem(I, L, R);
    }
  }
  long long L = 1LL << (h - 1), R = (1LL << h) - 1;
  int cor = 0;
  for (int i = 0; i < c1; i++) {
    L = max(B[i].L, L);
    R = min(B[i].R, R);
    if (L > R) {
      cor = 1;
      break;
    }
  }
  for (int i = 0; i < c1; i++) {
    if ((B[i].L <= L && B[i].R >= R) == false) {
      cor = 1;
      break;
    }
  }
  if (cor == 1) {
    puts("Game cheated!");
    return 0;
  }
  ge = 0;
  C[ge++] = 1LL << (h - 1);
  C[ge++] = (1LL << h) - 1;
  add(L);
  add(R);
  for (int i = 0; i < c0; i++) {
    add(A[i].L);
    add(A[i].R);
  }
  sort(C, C + ge);
  ge = unique(C, C + ge) - C;
  T.build(1, ge, 1);
  for (int i = 0; i < c0; i++) {
    T.cL = lower_bound(C, C + ge, A[i].L) - C + 1;
    T.cR = lower_bound(C, C + ge, A[i].R) - C + 1;
    T.update(1, ge, 1);
  }
  T.ans = 0;
  T.cL = lower_bound(C, C + ge, L) - C + 1;
  T.cR = lower_bound(C, C + ge, R) - C + 1;
  T.query(1, ge, 1);
  if (T.ans == 0) {
    puts("Game cheated!");
  } else if (T.ans > 1) {
    puts("Data not sufficient!");
  } else {
    printf("%I64d\n", C[T.loc - 1]);
  }
  return 0;
}
