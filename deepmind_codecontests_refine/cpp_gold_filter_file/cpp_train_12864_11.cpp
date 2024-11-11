#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long n, i, j, c1, c2, mx;
long long c[N];
vector<long long> t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long j1, j2;
  cin >> n;
  t.assign(n, LLONG_MAX);
  for (i = 0, mx = -1; i < n; i++) {
    cin >> t[i];
    if (t[i] <= mx) {
      c[i] = 0;
      continue;
    }
    j1 = lower_bound(t.begin(), t.end(), t[i] - 89) - t.begin();
    for (j = j1, c1 = 50; j < i; j++) {
      c1 -= c[j];
    }
    j2 = lower_bound(t.begin(), t.end(), t[i] - 1439) - t.begin();
    for (j = j2, c2 = 120; j < i; j++) {
      c2 -= c[j];
    }
    if (c1 > 20 and c2 > 20) {
      c[i] = 20;
      mx = t[i];
    } else if (c1 < c2) {
      c[i] = c1;
      mx = t[j1] + 89;
    } else {
      c[i] = c2;
      mx = t[j2] + 1439;
    }
  }
  for (i = 0; i < n; i++) cout << c[i] << "\n";
}
