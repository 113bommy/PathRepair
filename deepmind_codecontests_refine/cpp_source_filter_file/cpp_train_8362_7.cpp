#include <bits/stdc++.h>
using namespace std;
int sum, a[25], flag = 0;
int s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
int re[25], visit[25];
void add(int step, int x) {
  if (step <= 4)
    s1 += x;
  else if (step <= 8)
    s2 += x;
  else if (step <= 12)
    s3 += x;
  else
    s4 += x;
  if (step % 4 == 1)
    s5 += x;
  else if (step % 4 == 2)
    s6 += x;
  else if (step % 4 == 3)
    s7 += x;
  else
    s8 += x;
  if (step == 1 || step == 6 || step == 11 || step == 16) s9 += x;
  if (step == 4 || step == 7 || step == 10 || step == 13) s10 += x;
}
void sub(int step, int x) {
  if (step <= 4)
    s1 -= x;
  else if (step <= 8)
    s2 -= x;
  else if (step <= 12)
    s3 -= x;
  else
    s4 -= x;
  if (step % 4 == 1)
    s5 -= x;
  else if (step % 4 == 2)
    s6 -= x;
  else if (step % 4 == 3)
    s7 -= x;
  else
    s8 -= x;
  if (step == 1 || step == 6 || step == 11 || step == 16) s9 -= x;
  if (step == 4 || step == 7 || step == 10 || step == 13) s10 -= x;
}
int f[] = {0, 6, 7, 10, 11, 1, 16, 4, 13, 2, 3, 14, 15, 5, 8, 9, 12};
void dfs(int step) {
  if (step >= 6 && s9 != sum) return;
  if (step >= 8 && s10 != sum) return;
  if (step >= 10 && s1 != sum) return;
  if (step >= 12 && (s4 != sum || s6 != sum || s7 != sum)) return;
  if (step >= 14 && s2 != sum) return;
  if (step >= 16 && (s3 != sum || s5 != sum || s8 != sum)) return;
  if (flag) return;
  if (step == 16) {
    if (s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 && s5 == s6 && s6 == s7 &&
        s7 == s8 && s8 == s9 && s9 == s10) {
      flag = 1;
      printf("%d %d %d %d\n", re[1], re[2], re[3], re[4]);
      printf("%d %d %d %d\n", re[5], re[6], re[7], re[8]);
      printf("%d %d %d %d\n", re[9], re[10], re[11], re[12]);
      printf("%d %d %d %d\n", re[13], re[14], re[15], re[16]);
    }
    return;
  }
  for (int i = 1; i <= 16; i++) {
    if (visit[i]) continue;
    if (i > 1 && !visit[i - 1] && a[i] == a[i - 1]) continue;
    visit[i] = 1;
    add(f[step + 1], a[i]);
    re[f[step + 1]] = a[i];
    dfs(step + 1);
    sub(f[step + 1], a[i]);
    visit[i] = 0;
  }
}
bool cmp(int x, int y) { return x > y; }
int main() {
  memset(visit, 0, sizeof(visit));
  int n;
  scanf("%d", &n);
  sum = 0;
  for (int i = 1; i <= n * n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sum /= n;
  sort(a + 1, a + n * n + 1, cmp);
  printf("%d\n", sum);
  if (n == 1) {
    printf("%d\n", a[1]);
    return 0;
  }
  if (n < 4) {
    do {
      if (n == 2) {
        s1 = a[1] + a[2];
        s2 = a[1] + a[3];
        s3 = a[1] + a[4];
        s4 = a[2] + a[4];
        s5 = a[2] + a[3];
        s6 = a[3] + a[4];
        if (s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 && s5 == s6) {
          printf("%d %d\n", a[1], a[2]);
          printf("%d %d\n", a[3], a[4]);
          break;
        }
      } else {
        s1 = a[1] + a[2] + a[3];
        s2 = a[4] + a[5] + a[6];
        s3 = a[7] + a[8] + a[9];
        s4 = a[1] + a[5] + a[9];
        s5 = a[3] + a[5] + a[7];
        s6 = a[1] + a[4] + a[7];
        s7 = a[2] + a[5] + a[8];
        s8 = a[3] + a[6] + a[9];
        if (s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5 && s5 == s6 &&
            s6 == s7 && s7 == s8) {
          printf("%d %d %d\n", a[1], a[2], a[3]);
          printf("%d %d %d\n", a[4], a[5], a[6]);
          printf("%d %d %d\n", a[7], a[8], a[9]);
          break;
        }
      }
    } while (next_permutation(a + 1, a + n * n + 1));
    return 0;
  }
  s1 = s2 = s3 = s4 = s5 = s6 = s7 = s8 = s9 = s10 = 0;
  dfs(0);
  return 0;
}
