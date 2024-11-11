#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
map<int, int> m;
map<int, int>::iterator it;
void fact(int n) {
  int limit = sqrt(n + 1);
  for (int i = 2; i <= limit; i++) {
    if ((n % i) == 0) {
      m[i]++;
      while ((n % i) == 0) n /= i;
    }
  }
  if (n != 1) m[n]++;
}
int main() {
  int n, a, ans = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    fact(a);
  }
  for (it = m.begin(); it != m.end(); it++) {
    ans = max(ans, it->second);
  }
  printf("%d\n", ans);
  return 0;
}
