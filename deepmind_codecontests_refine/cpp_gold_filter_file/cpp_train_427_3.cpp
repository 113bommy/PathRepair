#include <bits/stdc++.h>
using namespace std;
int n;
int c[100010], d[100010];
multiset<int> s1, s2;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
    if (i) s1.insert(c[i] - c[i - 1]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    if (i) s2.insert(d[i] - d[i - 1]);
  }
  if (c[0] != d[0] || c[n - 1] != d[n - 1])
    puts("No");
  else if (s1 == s2)
    puts("Yes");
  else
    puts("No");
  return 0;
}
