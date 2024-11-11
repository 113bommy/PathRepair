#include <bits/stdc++.h>
using namespace std;
int cnt;
int Query(int x, int y) {
  cnt++;
  if (cnt == 300000) {
    while (1) {
    }
  }
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  int a;
  scanf("%d", &a);
  return a;
}
int Right(int ck, int x) {
  int i;
  for (i = 0; i < 3; i++) {
    int t = rand() % 10000 * 10000 + rand() % 1000;
    if (ck == 0) {
      if (Query(x, t)) return 0;
    } else {
      if (Query(t, x)) return 0;
    }
  }
  return 1;
}
int R[2][10100], CC[2];
void Ins(int ck, int x) { R[ck][CC[ck]++] = x; }
void Check(int ck, int a, int M, int b) {
  int i;
  if (b > 100000000) return;
  if (b + M <= 100000000) {
    if (!ck) {
      if (Query(a, b + M) >= M) {
        Check(ck, a, M, b + M + M);
        return;
      }
    } else {
      if (Query(b + M, a) >= M) {
        Check(ck, a, M, b + M + M);
        return;
      }
    }
  }
  for (i = 0; (1 << i) < M; i++) {
    int x, y;
    if (ck == 0) {
      x = a;
      y = b + (1 << i);
      if (y > 100000000) return;
    } else {
      y = a;
      x = b + (1 << i);
      if (x > 100000000) return;
    }
    int t = Query(x, y);
    if (t < (1 << i)) {
      if (ck == 0) {
        Ins(1, y + t);
        Check(ck, a, M, y + t);
        return;
      } else {
        Ins(0, x + t);
        Check(ck, a, M, x + t);
        return;
      }
    }
  }
  Check(ck, a, M, b + (1 << (i - 1)));
}
void Pro(int ck, int b) {
  int i, M = -1, x;
  for (i = 0; i <= CC[ck]; i++) {
    int b, e;
    if (i == 0)
      b = -100000000;
    else
      b = R[ck][i - 1];
    if (i == CC[ck])
      e = 100000000;
    else
      e = R[ck][i];
    if (e - b > M) {
      M = e - b;
      x = (e + b) / 2;
    }
  }
  M /= 2;
  Check(ck, x, M, b);
}
void Do(int x, int y) {
  int i = 0;
  if (x + 1024 <= 100000000 && y + 1024 <= 100000000 &&
      Query(x + 1024, y + 1024) >= 1024)
    i = 11;
  int bx = x, by = y;
  for (;; i++) {
    if (i >= 29) {
      return;
    }
    int ex = bx + (1 << i), ey = by + (1 << i);
    int ck = 0;
    if (ex > 100000000 && ey > 100000000) return;
    if (ex > 100000000) {
      Pro(0, by);
      return;
    }
    if (ey > 100000000) {
      Pro(1, bx);
      return;
    }
    int t = Query(ex, ey);
    if (!i && !t) {
      if (x != ex && Right(0, ex)) {
        Ins(0, ex);
        Do(ex, y);
        return;
      } else {
        Ins(1, ey);
        Do(x, ey);
        return;
      }
    } else if (t < (1 << i)) {
      if (ey + t > 100000000 ||
          (ex + t <= 100000000 &&
           !Query(min(ex + t, 100000000), min(ey + t - 1, 100000000)))) {
        Ins(0, ex + t);
        Do(ex + t, y);
        return;
      } else {
        Ins(1, ey + t);
        Do(x, ey + t);
        return;
      }
    }
  }
}
int main() {
  srand(1879);
  int t = Query(-100000000, -100000000);
  int i;
  int c1 = 0, c2 = 0;
  c1 = Right(1, -100000000 + t);
  c2 = Right(0, -100000000 + t);
  if (c1 && c2) {
    Ins(1, -100000000 + t);
    Ins(0, -100000000 + t);
    Do(-100000000 + t, -100000000 + t);
  } else if (c1) {
    Ins(1, -100000000 + t);
    Do(-100000000, -100000000 + t);
  } else {
    Ins(0, -100000000 + t);
    Do(-100000000 + t, -100000000);
  }
  printf("1 %d %d\n", CC[0], CC[1]);
  fflush(stdout);
  for (i = 0; i < CC[0]; i++) {
    printf("%d ", R[0][i]);
  }
  printf("\n");
  fflush(stdout);
  for (i = 0; i < CC[1]; i++) {
    printf("%d ", R[1][i]);
  }
  printf("\n");
  fflush(stdout);
}
