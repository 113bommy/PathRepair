#include <bits/stdc++.h>
using namespace std;
char a[1000100], ans[3000], s[3000], ans1[3000];
int tmp, p, i, len1, len12, len2, lens, k, o;
bool flag;
bool smaller() {
  for (int i = 1; i <= len2; i++)
    if (ans1[i] > ans[i])
      return false;
    else if (ans1[i] < ans[i])
      return true;
  return false;
}
bool ok1(int i) {
  for (int j = k; j >= 1; j--) {
    if (a[(j - 1) * len2 + i] != s[(j - 1) * p + tmp]) return false;
  }
  return true;
}
bool ok2(int i) {
  if (k * len2 + i > len1) return false;
  if (k * p + tmp > lens) return false;
  return (a[k * len2 + i] == s[k * p + tmp]);
}
int main() {
  gets(a + 1);
  gets(s + 1);
  scanf("%d", &len12);
  len1 = strlen(a + 1);
  lens = strlen(s + 1);
  if (len12 > len1)
    len2 = len1;
  else
    len2 = len12;
  for (i = 1; i <= len2; i++) ans[i] = '2';
  flag = false;
  k = len1 / len2;
  for (o = 0; o <= len2; o++)
    if ((lens - o) % k == 0 && o <= (lens - o) / k) {
      for (i = 1; i <= len2; i++) ans1[i] = '0';
      p = (lens - o) / k, tmp = p;
      for (i = len2; i >= 1 && tmp > 0; i--)
        if (tmp > o) {
          if (ok1(i) && k * len2 + i > len1) {
            ans1[i] = '1';
            tmp--;
          }
        } else if (ok2(i) && ok1(i)) {
          ans1[i] = '1';
          tmp--;
        }
      if (tmp == 0) {
        if (smaller()) {
          for (i = 1; i <= len2; i++) ans[i] = ans1[i];
          flag = true;
        }
      }
    }
  if (flag) {
    for (i = 1; i <= len2; i++) printf("%c", ans[i]);
    for (i = len2 + 1; i <= len12; i++) printf("0");
  } else
    printf("0\n");
  return 0;
}
