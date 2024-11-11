#include <bits/stdc++.h>
using namespace std;
int ask(int *A) {
  printf("? %d %d %d %d\n", A[0], A[1], A[2], A[3]);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
void solve1(int *A, const int &idx, int l, int r) {
  while (l <= r) {
    int mid = l + r >> 1;
    int x = A[idx];
    A[idx] = mid;
    if (ask(A) > 0) {
      l = mid + 1;
    } else {
      A[idx] = x;
      r = mid - 1;
    }
  }
}
void solve2(int *A, const int &idx, int l, int r) {
  while (l <= r) {
    int mid = l + r >> 1;
    int x = A[idx];
    A[idx] = mid;
    if (ask(A) > 0) {
      r = mid - 1;
    } else {
      A[idx] = x;
      l = mid + 1;
    }
  }
}
void init(int *A, int n) {
  A[0] = A[1] = 1;
  A[2] = A[3] = n;
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    vector<pair<int, int> > vs;
    int L = 1, R = n, U = n, D = 1;
    int A[5], B[5];
    init(A, n);
    init(B, n);
    solve1(A, 0, 1, n);
    B[0] = 1;
    B[3] = A[0] - 1;
    if (ask(A) == 1 && ask(B) == 1) {
      solve2(A, 2, A[0], n);
      solve1(A, 1, 1, n);
      solve2(A, 3, A[1], n);
      vs.emplace_back(A[0], A[1]);
      vs.emplace_back(A[2], A[3]);
      int r = A[0] - 1;
      init(A, n);
      A[2] = r;
      solve1(A, 0, 1, r);
      solve2(A, 2, A[0], r);
      solve1(A, 1, 1, n);
      solve2(A, 3, A[1], n);
      vs.emplace_back(A[0], A[1]);
      vs.emplace_back(A[2], A[3]);
    } else {
      init(A, n);
      solve1(A, 1, 1, n);
      solve2(A, 3, A[1], n);
      solve1(A, 0, 1, n);
      solve2(A, 2, A[0], n);
      int r = A[1] - 1;
      vs.emplace_back(A[0], A[1]);
      vs.emplace_back(A[2], A[3]);
      init(A, n);
      A[3] = r;
      solve1(A, 1, 1, r);
      solve2(A, 3, A[1], r);
      solve1(A, 0, 1, n);
      solve2(A, 2, A[0], n);
      vs.emplace_back(A[0], A[1]);
      vs.emplace_back(A[2], A[3]);
    }
    printf("!");
    for (auto p : vs) {
      printf(" %d %d", p.first, p.second);
    }
    printf("\n");
    fflush(stdout);
  }
  return 0;
}
