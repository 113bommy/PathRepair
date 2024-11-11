#include <bits/stdc++.h>
char s[100100];
int f1[10], f2[10];
int tmp[10];
int A[100100], B[100100];
int Max = 0, ansA[100100], ansB[100100], ansre;
inline int min(int a, int b) { return a < b ? a : b; }
void calc() {
  int now = 1, ans = 0;
  bool ok = 1;
  while (ok) {
    ans++;
    ok = 0;
    for (int i = 0; i <= 9; i++)
      if (f1[i] && f2[9 - i]) {
        f1[i]--;
        f2[9 - i]--;
        A[now] = i;
        B[now] = 9 - i;
        now++;
        ok = 1;
        break;
      }
  }
  ans += min(f1[0], f2[0]);
  if (ans > Max) {
    Max = ans;
    for (int i = 0; i < now; i++) ansA[i] = A[i], ansB[i] = B[i];
    int p = now;
    if (f1[0] < f2[0])
      ansre = f1[0], f2[0] -= f1[0], f1[0] = 0;
    else
      ansre = f2[0], f1[0] -= f2[0], f2[0] = 0;
    for (int i = 0; i < 10; i++)
      while (f1[i]) {
        ansA[p++] = i;
        f1[i]--;
      }
    p = now;
    for (int i = 0; i < 10; i++)
      while (f2[i]) {
        ansB[p++] = i;
        f2[i]--;
      }
  }
}
int main() {
  memset(ansA, -1, sizeof(ansA));
  scanf("%s", s);
  int m = strlen(s);
  for (int i = 0; i < m; i++) f1[s[i] - '0']++;
  for (int i = 0; i < 10; i++) f2[i] = f1[i];
  for (int i = 0; i < 10; i++) tmp[i] = f1[i];
  bool find = 0;
  for (int i = 1; i <= 9; i++) {
    if (f1[i] && f2[10 - i]) {
      A[0] = i;
      B[0] = 10 - i;
      f1[i]--;
      f2[10 - i]--;
      calc();
      find = 1;
    }
    for (int j = 0; j < 10; j++) f1[j] = f2[j] = tmp[j];
  }
  if (!find) {
    int p = 0;
    if (f1[0] < f2[0])
      ansre = f1[0], f2[0] -= f1[0], f1[0] = 0;
    else
      ansre = f2[0], f1[0] -= f2[0], f2[0] = 0;
    for (int i = 0; i < 10; i++)
      while (f1[i]) {
        ansA[p++] = i;
        f1[i]--;
      }
    p = 0;
    for (int i = 0; i < 10; i++)
      while (f2[i]) {
        ansB[p++] = i;
        f2[i]--;
      }
  }
  for (int i = m - 1 - ansre; i >= 0; i--) printf("%d", ansA[i]);
  for (int i = 0; i < ansre; i++) printf("0");
  puts("");
  for (int i = m - 1 - ansre; i >= 0; i--) printf("%d", ansB[i]);
  for (int i = 0; i < ansre; i++) printf("0");
  puts("");
  scanf(" ");
}
