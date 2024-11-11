#include <bits/stdc++.h>
using namespace std;
int con[200000];
int main() {
  int n;
  int ans = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &con[i]);
  }
  sort(con, con + n);
  for (int i = 0; i < n; i++) {
    if (ans < con[i]) ans++;
  }
  printf("%d", ans);
}
