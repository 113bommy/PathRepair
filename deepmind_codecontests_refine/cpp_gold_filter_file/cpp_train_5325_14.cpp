#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int stone[51];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &stone[i]);
  sort(stone + 1, stone + n + 1);
  if (stone[1] != stone[n / 2 + 1])
    printf("Alice\n");
  else
    printf("Bob\n");
  return 0;
}
