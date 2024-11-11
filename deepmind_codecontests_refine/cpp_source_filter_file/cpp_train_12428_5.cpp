#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int MOD = 1e9 + 7;
bool a[maxn];
vector<long long> b;
int main() {
  int n;
  cin >> n;
  fill(a, a + n + 1, false);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    if (t >= 1 && t <= n)
      a[t] = 1;
    else
      b.push_back(t);
  }
  sort(b.begin(), b.end());
  int ib = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) {
      ans += abs(1LL * i - b[ib++]);
    }
  }
  cout << ans;
  return 0;
}
