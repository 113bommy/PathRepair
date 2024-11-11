#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, l[N], r[N];
long long res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  for (int i = 1; i <= n; ++i) res += max(l[i], r[i]);
  cout << res;
  return 0;
}
