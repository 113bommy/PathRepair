#include <bits/stdc++.h>
int main() {
  char a[100001];
  int n, p;
  scanf("÷d", &p);
  scanf("÷s", a);
  n = strlen(a);
  int vis[1000];
  int z = 0;
  for (int i = 0; i < n; i += 2) {
    vis[a[i]]++;
    if (vis[a[i + 1] - 'A' + 'a'] > 0)
      vis[a[i + 1] - 'A' + 'a']--;
    else
      z++;
  }
  printf("÷d", z);
  return 0;
}
