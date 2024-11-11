#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, q, a, b, i, ans = 0;
  cin >> n >> k >> q;
  vector<long long int> v(200005, 0);
  vector<long long int> vsu(200005, 0);
  vector<long long int> vzo(200005, 0);
  while (n--) {
    cin >> a >> b;
    v[a] += 1;
    v[b + 1] -= 1;
  }
  for (i = 1; i < 200005; i++) v[i] = v[i] + v[i - 1];
  long long int c = 0;
  for (i = 1; i < 200005; i++) {
    if (v[i] >= k) {
      ++c;
    }
    vsu[i] = c;
  }
  while (q--) {
    cin >> a >> b;
    ans = vsu[b] - vsu[a - 1];
    cout << ans << "\n";
  }
  return 0;
}
