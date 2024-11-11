#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct node {
  long long int t, i, j, k;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, m, k, q, x, a, b, c, d, w;
  cin >> n;
  vector<node> vec(n + 1);
  vec[0].t = -1e9;
  vec[0].i = 0;
  vec[0].j = 0;
  vec[0].k = 0;
  for (int i = 1; i <= n; i++) {
    cin >> vec[i].t;
  }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    a = 0;
    b = 0;
    int low = 0, high = i, mid;
    while (low <= high) {
      mid = (high + low) / 2;
      if (vec[mid].t < vec[i].t - 1439) {
        a = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    low = 0;
    high = i;
    while (low <= high) {
      mid = (high + low) / 2;
      if (vec[mid].t < vec[i].t - 89) {
        b = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    vec[i].i = min({vec[i - 1].i, vec[i - 1].j, vec[i - 1].k}) + 20;
    vec[i].j = min({vec[b].i, vec[b].j, vec[b].k}) + 50;
    vec[i].k = min({vec[a].i, vec[a].j, vec[a].k}) + 120;
    cout << min({vec[i].i, vec[i].j, vec[i].k}) - ans << "\n";
    ans = min({vec[i].i, vec[i].j, vec[i].k});
  }
  return 0;
}
