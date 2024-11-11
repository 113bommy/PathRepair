#include <bits/stdc++.h>
using namespace std;
int n;
int p1[200005];
int p2[200005];
int pos1, pos2;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", p1 + i);
  for (int i = 0; i < n; ++i) scanf("%d", p2 + i);
  for (pos2 = 0; pos2 < n; pos2++)
    if (p1[pos1] == p2[pos2]) pos1++;
  printf("%d", n - pos1 - 1);
  return 0;
}
