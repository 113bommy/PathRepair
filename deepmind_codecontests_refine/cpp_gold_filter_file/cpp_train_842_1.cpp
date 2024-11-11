#include <bits/stdc++.h>
using namespace std;
long long tests;
long long n, k = 1, l, cnt, r, c;
bool z;
void solve() {
  cin >> n;
  k = ceil(sqrt(n));
  l = (n - 1) / k + 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= n / 3; j++) {
      r = i / 3 * 8 + 1;
      if (i % 3 == 1) r += 3;
      c = j * 2 + 1;
      if (i % 3) c++;
      cout << r << " " << c << endl;
      cnt++;
      if (cnt == n) return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
}
