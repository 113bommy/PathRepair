#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  long long int x = 0;
  scanf("%d", &n);
  bool used[n];
  char ch[n];
  int val[n];
  memset(used, false, sizeof(used));
  getchar();
  for (i = 0; i < n; i++) scanf("%c", &ch[i]);
  for (i = 0; i < n; i++) scanf("%d", &val[i]);
  if (ch[0] == '>')
    x += val[0];
  else {
    printf("INFINITE");
    return 0;
  }
  while (1) {
    if (x < 0 || x >= n) {
      printf("FINITE");
      return 0;
    }
    if (!used[x]) {
      used[x] = true;
      if (ch[x] == '>')
        x += val[x];
      else
        x -= val[x];
    } else {
      printf("INFINITE");
      return 0;
    }
  }
  return 0;
}
