#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, p, ok = 0;
char str[1005];
int strr[1005];
bool check(int pos) {
  if (pos >= 1 && strr[pos] == strr[pos - 1]) return 0;
  if (pos >= 2 && strr[pos] == strr[pos - 2]) return 0;
  return 1;
}
int main(int argc, char* argv[]) {
  scanf("%d %d %s", &n, &p, str);
  if (p == 1) {
    printf("NO\n");
    return 0;
  }
  for (int i = 0; i < n; i++) strr[i] = str[i] - 'a';
  int v = n - 1;
  while (1) {
    if (v < 0) break;
    if (v == n) {
      ok = 1;
      break;
    }
    if (strr[v] == p - 1)
      strr[v] = -1, v--;
    else {
      strr[v] = (strr[v] + 1) % p;
      if (check(v)) v++;
    }
  }
  if (!ok)
    printf("NO");
  else
    for (int i = 0; i < n; i++) {
      printf("%c", strr[i] + 'a');
    }
  printf("\n");
  return 0;
}
