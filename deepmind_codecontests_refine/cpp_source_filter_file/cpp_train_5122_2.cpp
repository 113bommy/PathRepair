#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  int ans = -1;
  for (int i = 1; i <= 100; i++) {
    int x = n - p * i;
    if (x <= i) continue;
    if ((__builtin_popcount(x)) <= i) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
