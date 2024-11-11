#include <bits/stdc++.h>
using namespace std;
char s1[131027];
char s2[131072];
char s3[131072];
int p[131072];
int l1, l2, l3, ans;
void next(char s[], int len) {
  p[1] = 0;
  int j = 0;
  for (int i = 2; i <= len; i++) {
    while (j && s[i] != s[j + 1]) j = p[j];
    if (s[i] == s[j + 1]) j++;
    p[i] = j;
  }
}
int kmp(char s1[], int l1, char s2[], int l2) {
  next(s2, l2);
  int j = 0;
  for (int i = 1; i <= l1; i++) {
    while (j && s1[i] != s2[j + 1]) j = p[j];
    if (s1[i] == s2[j + 1]) j++;
    if (j == l2) return l2;
  }
  return j;
}
int calc(char s1[], int l1, char s2[], int l2, char s3[], int l3) {
  int ans = l1 + l2 + l3;
  int tmp = kmp(s1, l1, s2, l2);
  ans -= tmp;
  if (tmp == l2)
    ans -= kmp(s1, l1, s3, l3);
  else
    ans -= kmp(s2, l2, s3, l3);
  return ans;
}
int main() {
  while (scanf("%s\n", s1 + 1) == 1) {
    scanf("%s\n", s2 + 1);
    scanf("%s\n", s3 + 1);
    l1 = strlen(s1 + 1);
    l2 = strlen(s2 + 1);
    l3 = strlen(s3 + 1);
    ans = 0x7fffffff;
    ans = min(calc(s1, l1, s2, l2, s3, l3), ans);
    ans = min(calc(s1, l1, s3, l3, s2, l2), ans);
    ans = min(calc(s2, l2, s1, l1, s3, l3), ans);
    ans = min(calc(s2, l2, s3, l3, s1, l1), ans);
    ans = min(calc(s3, l3, s1, l1, s2, l2), ans);
    ans = min(calc(s3, l3, s2, l2, s1, l1), ans);
    printf("%d\n", ans);
  }
  return 0;
}
