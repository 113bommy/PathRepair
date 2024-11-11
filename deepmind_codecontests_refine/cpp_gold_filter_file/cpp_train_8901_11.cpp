#include <bits/stdc++.h>
int CoS[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int GetCountOfSegment(int a) {
  int iSum = 0;
  int i = 0;
  int iLen;
  char strA[20];
  sprintf(strA, "%d", a);
  iLen = strlen(strA);
  for (i = 0; i < iLen; i++) {
    iSum += CoS[strA[i] - '0'];
  }
  return iSum;
}
int main() {
  int a, b;
  int iSum = 0;
  int i;
  scanf("%d%d", &a, &b);
  for (i = a; i <= b; i++) {
    iSum += GetCountOfSegment(i);
  }
  printf("%d", iSum);
  return 0;
}
