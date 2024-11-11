#include <bits/stdc++.h>
using namespace std;
long long c, h1, h2, w1, w2;
long long ans = 0;
void work() {
  for (long long i = 0; i <= c / w1; i++) {
    ans = max(ans, i * h1 + (c - i * w1) / w2 * h2);
  }
  cout << ans;
}
void work2() {
  for (long long i = 0; i <= w2; i++) {
    ans = max(ans, i * h1 + (c - i * w1) / w2 * h2);
  }
  for (long long i = 0; i <= w1; i++) {
    ans = max(ans, i * h2 + (c - i * w2) / w1 * h1);
  }
  cout << ans;
}
int main() {
  cin >> c >> h1 >> h2 >> w1 >> w2;
  if (w1 < w2) swap(w1, w2), swap(h1, h2);
  if (w1 > sqrt(c))
    work();
  else
    work2();
}
