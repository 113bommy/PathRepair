#include <bits/stdc++.h>
struct amount {
  int a, b, c;
  int endingA;
};
char str1[100001], str2[100001];
amount tot1[100001], tot2[100001];
char result[100001];
int main() {
  scanf("%s", str1);
  scanf("%s", str2);
  tot1[0].a = 0;
  tot1[0].b = 0;
  tot1[0].c = 0;
  tot1[0].endingA = 0;
  for (int i = 0; str1[i]; i++) {
    tot1[i + 1].a = tot1[i].a;
    tot1[i + 1].b = tot1[i].b;
    tot1[i + 1].c = tot1[i].c;
    if (str1[i] == 'A') {
      tot1[i + 1].a++;
    } else if (str1[i] == 'B') {
      tot1[i + 1].b++;
    } else if (str1[i] == 'C') {
      tot1[i + 1].c++;
    }
    tot1[i + 1].endingA = str1[i] == 'A' ? tot1[i].endingA + 1 : 0;
  }
  for (int i = 0; str2[i]; i++) {
    tot2[i + 1].a = tot2[i].a;
    tot2[i + 1].b = tot2[i].b;
    tot2[i + 1].c = tot2[i].c;
    if (str2[i] == 'A') {
      tot2[i + 1].a++;
    } else if (str2[i] == 'B') {
      tot2[i + 1].b++;
    } else if (str2[i] == 'C') {
      tot2[i + 1].c++;
    }
    tot2[i + 1].endingA = str2[i] == 'A' ? tot2[i].endingA + 1 : 0;
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int l1, r1, l2, r2;
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    l1--;
    l2--;
    int a1 = tot1[r1].a - tot1[l1].a;
    int b1 = tot1[r1].b - tot1[l1].b;
    int c1 = tot1[r1].c - tot1[l1].c;
    int endA1 = tot1[r1].endingA;
    int a2 = tot2[r2].a - tot2[l2].a;
    int b2 = tot2[r2].b - tot2[l2].b;
    int c2 = tot2[r2].c - tot2[l2].c;
    int endA2 = tot2[r2].endingA;
    if (endA1 > r1 - l1) {
      endA1 = r1 - l1;
    }
    if (endA2 > r2 - l2) {
      endA2 = r2 - l2;
    }
    if (b1 + c1 > b2 + c2) {
      result[i] = '0';
      continue;
    }
    if ((b1 + c1) % 2 != (b2 + c2) % 2) {
      result[i] = '0';
      continue;
    }
    if (endA2 > endA1) {
      result[i] = '0';
      continue;
    }
    if (endA2 < endA1 && endA2 % 3 != endA1 % 3 && b1 + c1 == b2 + c2) {
      result[i] = '0';
      continue;
    }
    if (b1 + c1 == 0 && c2 + c2 > 0 && endA1 == endA2) {
      result[i] = '0';
      continue;
    }
    result[i] = '1';
  }
  result[n] = 0;
  printf("%s", result);
  return 0;
}
