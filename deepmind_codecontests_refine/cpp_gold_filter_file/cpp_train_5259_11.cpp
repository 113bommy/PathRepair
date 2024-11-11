#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
#pragma GCC optimize("O500")
using namespace std;
const bool db = false;
int a[100100], b[100100];
int main() {
  int n;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) scanf("%d ", &a[i]), b[a[i]] = i;
  int cnt = 0, temp = 1;
  for (int i = 1; i < n; i++) {
    if (b[i] < b[i + 1])
      temp++;
    else
      cnt = max(cnt, temp), temp = 1;
  }
  cnt = max(cnt, temp);
  printf("%d\n", n - cnt);
  return 0;
}
