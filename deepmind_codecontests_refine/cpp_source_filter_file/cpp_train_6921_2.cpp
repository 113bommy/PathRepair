#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max();
const long long linf = numeric_limits<long long>::max();
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a;
  a.resize(n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  long long till = a[0];
  int ans = 1;
  for (int i = 0; i < (n); ++i) {
    if (i == 0) continue;
    if (a[i] >= till) ans++;
    till += a[i];
  }
  cout << ans;
  return 0;
}
