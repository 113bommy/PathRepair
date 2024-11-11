#include <bits/stdc++.h>
using namespace std;
std::map<int, int> m;
set<int> s;
int l, r;
void fac(int n) {
  if (n * 2 > r) return;
  m[n * 2] = 1;
  if (n * 3 > r) return;
  m[n * 3] = 1;
  if (!m[n * 4]) fac(n * 2);
  fac(n * 3);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> l >> r;
  int ans = 0;
  for (long long i = 1; i <= r; i *= 2) {
    for (long long j = 1; j <= r; j *= 3) {
      if (i * j <= r and l <= i * j) ans++;
    }
  }
  cout << ans;
  return 0;
}
