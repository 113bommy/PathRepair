#include <bits/stdc++.h>
long long sum, n[10];
int t;
int findmax() {
  int i, m;
  m = 0;
  sum = 0;
  for (i = 1; i <= 4; ++i) {
    if (n[i] >= n[m]) m = i;
    sum += n[i];
  }
  if (n[m] > 2)
    return m;
  else
    return 0;
}
int findnext(int j) {
  int i;
  for (i = j + 1; j <= 4; ++i) {
    if (n[i] == 2) return i;
  }
}
void out() {
  for (int i = 1; i <= 4; ++i) printf("%d ", n[i]);
  printf("\n");
}
int main() {
  int a, b, c, d;
  while (scanf("%I64d%I64d%I64d%I64d", &n[1], &n[2], &n[3], &n[4]) != EOF) {
    n[0] = 0;
    while (a = findmax()) {
      b = a - 1;
      if (b == 0) b = 4;
      c = a + 1;
      if (c == 5) c = 1;
      d = 10 - a - b - c;
      if (n[a] & 1) {
        if (n[b] & 1) {
          printf("+%d\n/%d\n", b, b);
          n[a]++;
          n[b]++;
          n[a] /= 2;
          n[b] /= 2;
        } else if (n[c] & 1) {
          printf("+%d\n/%d\n", a, a);
          n[a]++;
          n[c]++;
          n[a] /= 2;
          n[c] /= 2;
        } else {
          printf("+%d\n/%d\n", a, b);
          n[a]++;
          n[c]++;
          n[a] /= 2;
          n[b] /= 2;
        }
      } else {
        if (!(n[b] & 1)) {
          printf("/%d\n", b);
          n[a] /= 2;
          n[b] /= 2;
        } else if (!(n[c] & 1)) {
          printf("/%d\n", a);
          n[a] /= 2;
          n[c] /= 2;
        } else {
          printf("+%d\n/%d\n", d, b);
          n[d]++;
          n[b]++;
          n[a] /= 2;
          n[b] /= 2;
        }
      }
    }
    if (sum == 5) {
      a = findnext(0);
      if (a == 1)
        b = 4;
      else
        b = a - 1;
      printf("+%d\n", b);
      printf("+%d\n", a);
      printf("/%d\n", a);
      printf("/%d\n", b);
    }
    if (sum == 6) {
      a = findnext(0);
      b = findnext(a);
      if (b - a == 1) printf("/%d\n", a);
      if (b == 4 && a == 1) printf("/%d\n", b);
      if (b - a == 2) {
        c = a - 1;
        if (c == 0) c = 4;
        d = b - 1;
        printf("+%d\n", c);
        printf("+%d\n", a);
        printf("/%d\n", c);
        printf("/%d\n", d);
        printf("+%d\n", c);
        printf("+%d\n", a);
        printf("/%d\n", a);
        printf("/%d\n", c);
      }
    }
    if (sum == 7) {
      a = findnext(0);
      b = findnext(a);
      c = findnext(b);
      d = 10 - a - b - c;
      if (d - b == 2) {
        t = a;
        a = c;
        c = t;
        t = b;
        b = c;
        c = t;
      }
      printf("/%d\n", b);
      c = a - 1;
      if (c == 0) c = 4;
      printf("+%d\n", c);
      printf("+%d\n", a);
      printf("/%d\n", a);
      printf("/%d\n", c);
    }
    if (sum == 8) {
      printf("/1\n/3\n");
    }
  }
  return 0;
}
