#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  map<int, int> m;
  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x == 0) continue;
    m[x]++;
  }
  map<int, int>::iterator it;
  int npair = 0;
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second == 3) {
      npair = -1;
      break;
    } else if (it->second == 2)
      npair++;
  }
  printf("%d\n", npair);
  return 0;
}
