#include <bits/stdc++.h>
using namespace std;
int casenum, lnth, cnt, ind, cur;
string s;
bool ok[101];
int arr[101];
string getss() {
  string k = "";
  char a;
  a = getchar();
  while (a == -1 || a == 32 || a == 10) a = getchar();
  while (a != -1 && a != 32 && a != 10) {
    k += a;
    a = getchar();
  }
  return k;
}
void calc1() {
  scanf("%d", &cnt);
  if (cnt < 1) {
    puts("NULL");
    return;
  }
  cur = 0;
  for (int i = 0; i < lnth; i++) {
    if (arr[i] > 0) {
      cur = 0;
      continue;
    }
    cur++;
    if (cur == cnt) {
      for (int j = 0; j < cnt; j++) {
        arr[i - j] = ind;
      }
      ok[ind] = true;
      break;
    }
  }
  if (cur < cnt)
    puts("NULL");
  else
    printf("%d\n", ind++);
}
void calc2() {
  scanf("%d", &cnt);
  if (cnt < 1 || cnt > lnth) {
    puts("ILLEGAL_ERASE_ARGUMENT");
    return;
  }
  for (int i = 0; i < lnth; i++)
    if (arr[i] == cnt) arr[i] = 0;
  if (!ok[cnt])
    puts("ILLEGAL_ERASE_ARGUMENT");
  else
    ok[cnt] = false;
}
void calc3() {
  cnt = 0;
  for (int i = 0; i < lnth; i++)
    if (arr[i] > 0) arr[cnt++] = arr[i];
  for (int i = cnt; i < lnth; i++) arr[i] = 0;
}
int main() {
  scanf("%d%d", &casenum, &lnth);
  memset(arr, 0, sizeof arr);
  memset(ok, false, sizeof ok);
  ind = 1;
  for (int i = 0; i < casenum; i++) {
    s = getss();
    if (s == "alloc") calc1();
    if (s == "erase") calc2();
    if (s == "defragment") calc3();
  }
  return 0;
}
