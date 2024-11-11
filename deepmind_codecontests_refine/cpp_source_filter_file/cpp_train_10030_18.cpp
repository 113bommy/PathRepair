#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, r;
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &r);
  long long area = a * b;
  long long areaP = (2 * r) * (2 * r);
  if (2 * r >= max(a, b))
    cout << "First";
  else
    cout << "Second";
}
int main() {
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
