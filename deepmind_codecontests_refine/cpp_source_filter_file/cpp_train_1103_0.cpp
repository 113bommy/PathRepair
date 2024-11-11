#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string n;
long long a[N], k;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> k >> n;
  int m = n.size();
  long long s = 0;
  for (int i = 0; i < m; i++) {
    a[i] = n[i] - '0';
    s += a[i];
  }
  sort(a, a + m);
  long long ans = 0, i = 0;
  while (s < k) {
    ans++;
    s += (9 - a[i]);
  }
  cout << ans << endl;
  return 0;
}
