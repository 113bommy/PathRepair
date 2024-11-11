#include <bits/stdc++.h>
using namespace std;
const long long int huge = 1e17;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int abbs(long long int a, long long int b) {
  if (a - b < 0) return b - a;
  return a - b;
}
long long int lowerB(vector<long long int> &v, long long int val) {
  long long int ind = v.size(), l = 0, r = v.size(), mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] >= val) {
      ind = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ind;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> segs(n * k + 5);
  vector<long long int> v(k + 1);
  for (long long int i = 0; i < k; i++) {
    cin >> v[i];
    segs[v[i]] = 1;
  }
  vector<vector<long long int> > ans;
  vector<long long int> rem;
  for (long long int i = 1; i <= n * k; i++)
    if (!segs[i]) rem.push_back(i);
  long long int kk = 0;
  for (long long int i = 0; i < k; i++) {
    vector<long long int> t;
    t.push_back(v[i]);
    for (long long int i = 0; i < n - 1; i++) t.push_back(rem[kk++]);
    ans.push_back(t);
  }
  for (auto cv : ans) {
    for (long long int x : cv) cout << x << " ";
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
}
