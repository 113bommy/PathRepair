#include <bits/stdc++.h>
using namespace std;
long long n, i = 0, x, y, ans[100005], q, z, t1, t2, j;
vector<long long> a, b, c;
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  cin >> n >> q;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for (i = 0; i < n; i++)
    cin >> a[i], b[i] = c[i] = a[i],
                 (i == 0) ? ans[i] = a[i] : ans[i] = max(a[i], ans[i - 1]);
  x = *max_element(a.begin(), a.end());
  y = max_element(a.begin(), a.end()) - a.begin();
  for (i = 0; i < y - 1; i++) {
    if (c[i] > c[i + 1]) swap(c[i], c[i + 1]);
  }
  for (i = 0; i < n; i++) {
    a[i] = c[j];
    j++;
    j %= n;
  }
  while (q--) {
    cin >> z;
    if (z <= y) {
      cout << ans[z - 1] << " " << b[z] << endl;
    } else {
      z -= y;
      z--;
      z = (z % (n - 1));
      cout << x << " " << a[z + 1] << endl;
    }
  }
  return 0;
}
