#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
int main() {
  int t;
  scanf("%d", &t);
  int mx = -1, my = -1;
  while (t--) {
    char c;
    int t1, t2;
    scanf("%c %d %d", &c, &t1, &t2);
    if (t1 > t2) swap(t1, t2);
    if (c == '+') {
      mx = max(mx, t1);
      my = max(my, t2);
    } else {
      if (mx <= t1 && my <= t2)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}
