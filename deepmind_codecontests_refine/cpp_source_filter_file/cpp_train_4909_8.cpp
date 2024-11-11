#include <bits/stdc++.h>
using namespace std;
const int MAX = 300000005;
bitset<MAX> p;
int l, r;
void seive() {
  int i, j, ans = 0;
  for (i = 2; i * i <= r; i++) {
    if (!p[i]) {
      for (j = i * i; j <= r; j += i) {
        p[j] = true;
      }
    }
  }
  for (i = 5; i <= r; i += 4) {
    if (!p[i] && i >= l) {
      ans++;
    }
  }
  if (l <= 2 && r <= 2) ans++;
  printf("%d\n", ans);
}
int main() {
  cin >> l >> r;
  seive();
  return 0;
}
