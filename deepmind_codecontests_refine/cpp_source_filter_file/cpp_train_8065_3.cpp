#include <bits/stdc++.h>
const int N = 200200;
using namespace std;
int n;
long long a[N];
long long d[N][2];
vector<int> v[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p >> a[i];
    if (p != -1) v[p].push_back(i);
  }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    for (auto y : v[i]) {
      int f0 = d[i][0], f1 = d[i][1];
      d[i][0] = max(f0 + d[y][0], d[i][0]);
      d[i][1] = max(f0 + d[y][1], d[i][1]);
      if (f1) {
        d[i][0] = max(d[i][0], f1 + d[y][1]);
        d[i][1] = max(d[i][1], f1 + d[y][0]);
      }
    }
    d[i][1] = max(d[i][1], d[i][0] + a[i]);
    ans = max(ans, d[i][1]);
  }
  cout << ans << endl;
}
