#include <bits/stdc++.h>
int a[1000000 + 1];
int b[1000000 + 1];
int Pos[1000000 + 1];
int MaxLen[1000000 + 1];
bool IsClockWise(int a, int b, int c) {
  if (a <= b && b <= c) return true;
  if (a <= b && c <= a) return true;
  if (b <= c && c <= a) return true;
  return false;
}
void Cal_MaxLen(int i, int la) {
  if (Pos[a[i]] == -1) {
    MaxLen[i] == 0;
    return;
  }
  int begin, end;
  end = (i - 1 + la) % la;
  begin = (end - MaxLen[end] + 1 + la) % la;
  if (MaxLen[end] == 0) {
    if (Pos[a[i]] != -1)
      MaxLen[i] = 1;
    else
      MaxLen[i] = 0;
    return;
  }
  do {
    if (IsClockWise(Pos[a[begin]], Pos[a[end]], Pos[a[i]])) break;
    begin = (begin + 1) % la;
  } while (1);
  if (i >= begin)
    MaxLen[i] = i - begin + 1;
  else
    MaxLen[i] = i - begin + 1 + la;
}
void Find_SubStr() {
  int la, lb;
  int i, j;
  scanf("%d%d", &la, &lb);
  for (i = 0; i < la; i++) scanf("%d", a + i);
  for (j = 0; j < lb; j++) scanf("%d", b + j);
  memset(Pos, -1, sizeof(Pos));
  for (j = 0; j < lb; j++) Pos[b[j]] = j;
  memset(MaxLen, 0, sizeof(MaxLen));
  for (i = 0; i < la; i++) Cal_MaxLen(i, la);
  i = 0;
  while (i < la - 1) {
    Cal_MaxLen(i, la);
    if (MaxLen[i] <= i + 1) break;
    i++;
  }
  int Max = 0;
  for (i = 0; i < la; i++)
    if (MaxLen[i] > Max) Max = MaxLen[i];
  printf("%d\n", Max);
}
int main() {
  Find_SubStr();
  return 0;
}
