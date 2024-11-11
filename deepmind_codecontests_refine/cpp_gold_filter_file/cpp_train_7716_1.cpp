#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 30; i >= 0; i--) {
    if (n & (1 << i)) s.insert(i);
  }
  int len = s.size();
  if (n < k || len > k) {
    printf("NO");
  } else {
    printf("YES\n");
    multiset<int>::iterator i;
    while (s.size() < k) {
      i = (--s.end());
      int now = *i;
      s.erase(i);
      s.insert(now - 1);
      s.insert(now - 1);
    }
    for (i = s.begin(); i != s.end(); i++) {
      printf("%d ", 1 << *i);
    }
  }
  return 0;
}
