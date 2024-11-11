#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1ll << 50;
const long long maxn = 100005;
long long ar[maxn], v[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, l, wm;
  cin >> n >> l >> wm;
  vector<pair<long long, long long> > vec;
  vector<long long> negvec;
  for (int i = 0; i < n; i++) {
    cin >> ar[i] >> v[i];
    vec.push_back({ar[i], i});
    if (v[i] == -1) {
      negvec.push_back(ar[i]);
    }
  }
  sort(vec.begin(), vec.end());
  sort(negvec.begin(), negvec.end());
  long long ans = 0;
  for (auto it : vec) {
    int pos = it.first;
    int idx = it.second;
    int vel = v[idx];
    if (vel == 1) {
      long long maxvel;
      if (pos <= 0) {
        maxvel = wm + 1;
      } else {
        maxvel = wm - 1;
      }
      if (maxvel == 0) {
        continue;
      }
      long long limit = (2 * abs(pos) / (maxvel)) + pos - l;
      long long num =
          negvec.end() - upper_bound(negvec.begin(), negvec.end(), limit);
      ans += num;
    }
  }
  cout << ans << endl;
  return 0;
}
