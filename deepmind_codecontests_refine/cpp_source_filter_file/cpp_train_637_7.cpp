#include <bits/stdc++.h>
using namespace std;
int chest[100001];
int key[100001];
int oddchest, oddkey;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", chest + i);
    if (chest[i] % 2 == 1) oddchest++;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", key + i);
    if (key[i] % 2 == 1) oddkey++;
  }
  printf("%d", min(oddkey, n - oddchest) + min(oddchest, n - oddkey));
  return 0;
}
