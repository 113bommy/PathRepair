#include <bits/stdc++.h>
using namespace std;
long long Q;
long long n;
long long a[300005];
long long l[300005], r[300005];
vector<long long> comp;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    comp.clear();
    for (int i = 1; i <= n; i++) comp.push_back(a[i]);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 1; i <= n; i++)
      a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    long long N = comp.size();
    for (int i = 0; i < N; i++) l[i] = 1e18, r[i] = -1e18;
    for (long long i = 1; i <= n; i++) {
      l[a[i]] = min(l[a[i]], i);
      r[a[i]] = max(r[a[i]], i);
    }
    int cnt = 1, ans = 0;
    for (int i = 1; i < N; i++) {
      if (r[i - 1] < l[i])
        cnt++;
      else
        cnt = 1;
      ans = max(ans, cnt);
    }
    cout << N - ans << "\n";
  }
  flush(cout);
  return 0;
}
