#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 100005;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
int n;
char s[N];
struct Number {
  int a[N];
  void Init() {
    memset(a, 0, sizeof(a));
    a[0] = 1;
  }
  void Print() {
    for (int i = a[0]; i >= 1; i--) {
      printf("%d", a[i]);
    }
    printf("\n");
  }
};
Number Plas(Number A, Number B) {
  A.a[0] = max(A.a[0], B.a[0]);
  for (int i = 1; i <= A.a[0]; i++) A.a[i] += B.a[i];
  for (int i = 1; i <= A.a[0]; i++) {
    A.a[i + 1] += A.a[i] / 10;
    A.a[i] %= 10;
    if (A.a[A.a[0] + 1]) A.a[0]++;
  }
  return A;
}
Number Cut(Number A, int pos) {
  Number B;
  Number C;
  B.Init();
  C.Init();
  B.a[0] = pos;
  C.a[0] = A.a[0] - pos;
  for (int i = 1; i <= B.a[0]; i++) B.a[i] = A.a[i];
  for (int i = 1; i <= C.a[0]; i++) C.a[i] = A.a[pos + i];
  return Plas(B, C);
}
Number Min(Number A, Number B) {
  if (A.a[0] != B.a[0]) {
    if (A.a[0] < B.a[0]) return A;
    if (A.a[0] > B.a[0]) return B;
  }
  for (int i = A.a[0]; i >= 1; i--) {
    if (A.a[i] < B.a[i]) return A;
    if (A.a[i] > B.a[i]) return B;
  }
  return A;
}
int main() {
  Number A;
  Number Ans;
  A.Init();
  Ans.Init();
  Ans.a[0] = inf;
  n = read();
  A.a[0] = n;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) A.a[i] = s[n - i + 1] - '0';
  for (int i = n / 2; i >= 1; i--) {
    if (A.a[i] != 0) {
      Ans = Min(Ans, Cut(A, i));
      break;
    }
  }
  for (int i = n / 2 + 1; i < n; i++) {
    if (A.a[i] != 0) {
      Ans = Min(Ans, Cut(A, i));
      break;
    }
  }
  Ans.Print();
  return 0;
}
