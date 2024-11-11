#include <bits/stdc++.h>
using namespace std;
const int Mn = 100000 + 10;
int n, a[Mn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int pos(1), tot(1);
  int cnt(0);
  for (int i = 1; i <= n; i++)
    if (a[i] == a[1] + 1) cnt++;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[pos])
      tot++;
    else if (a[i] == a[pos] + 1)
      tot--;
    else {
      puts("NO");
      return 0;
    }
    if (tot == 0) tot = 1, pos = i;
  }
  if (n & 1 || tot >= 2)
    puts("NO");
  else if (n == 2 || (n > 2 && cnt > 1))
    puts("YES");
  else
    puts("No");
  return 0;
}
