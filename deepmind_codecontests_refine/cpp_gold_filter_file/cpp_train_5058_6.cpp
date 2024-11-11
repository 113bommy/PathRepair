#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n{};
  cin >> n;
  long long int r1_min = 9999999999, l1_max = -1;
  for (int i = 0; i < n; i++) {
    long long int l{}, r{};
    cin >> l >> r;
    l1_max = max(l1_max, l);
    r1_min = min(r1_min, r);
  }
  long long int m{};
  cin >> m;
  long long int l2_max = -1, r2_min = 9999999999;
  for (int i = 0; i < m; i++) {
    long long int l{}, r{};
    cin >> l >> r;
    l2_max = max(l2_max, l);
    r2_min = min(r2_min, r);
  }
  if ((l2_max <= r1_min) && (l1_max <= r2_min))
    cout << 0 << endl;
  else
    cout << max((l1_max - r2_min), (l2_max - r1_min)) << endl;
  return 0;
}
