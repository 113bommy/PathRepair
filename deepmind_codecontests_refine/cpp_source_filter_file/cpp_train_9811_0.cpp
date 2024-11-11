#include <bits/stdc++.h>
using namespace std;
long long int ans = LLONG_MAX;
long long int r, g, b;
void findMin(vector<long long int> x, vector<long long int> y,
             vector<long long int> z) {
  for (long long int i = 0; i < y.size(); ++i) {
    long long int t = upper_bound(x.begin(), x.end(), y[i]) - x.begin();
    long long int s = lower_bound(z.begin(), z.end(), y[i]) - z.begin();
    if (t == 0) continue;
    if (s == z.size()) continue;
    --t;
    ans = min(ans,
              ((x[t] - y[i]) * (x[t] - y[i]) + (z[s] - y[i]) * (z[s] - y[i]) +
               (x[t] - z[s]) * (x[t] - z[s])));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int ttt;
  cin >> ttt;
  for (long long int yui = 0; yui < ttt; ++yui) {
    cin >> r >> g >> b;
    vector<long long int> ra(r), ba(b), ga(g);
    for (long long int i = 0; i < r; ++i) {
      cin >> ra[i];
    }
    for (long long int i = 0; i < g; ++i) {
      cin >> ga[i];
    }
    for (long long int i = 0; i < b; ++i) {
      cin >> ba[i];
    }
    sort(ra.begin(), ra.end());
    sort(ga.begin(), ga.end());
    sort(ba.begin(), ba.end());
    findMin(ra, ga, ba);
    findMin(ra, ba, ga);
    findMin(ba, ra, ga);
    findMin(ba, ga, ra);
    findMin(ra, ba, ga);
    findMin(ra, ga, ba);
    cout << ans << endl;
    ans = LLONG_MAX;
  }
  return 0;
}
