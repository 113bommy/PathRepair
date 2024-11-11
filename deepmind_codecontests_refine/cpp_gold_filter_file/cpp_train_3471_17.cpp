#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, k;
  long long int b;
  cin >> n >> k >> b;
  vector<pair<int, int> > v(n);
  for (int(i) = (0); (i) < (n); (i)++) cin >> v[i].first;
  for (int(i) = (0); (i) < (n); (i)++) v[i].second = i;
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  long long int sum = 0;
  vector<int> mark(n, 0);
  int cnt = 0;
  int i = 0;
  int last = 0;
  while (i < n and cnt < k) {
    if (v[i].second != n - 1) {
      sum += v[i].first;
      mark[v[i].second] = 1;
      last = v[i].first;
      cnt++;
    }
    i++;
  }
  int ans = n - 1;
  for (int(i) = (0); (i) < (n); (i)++) {
    long long int t = sum;
    int index = v[i].second;
    if (mark[index] == 0) {
      t -= last;
      t += v[i].first;
    }
    if (t > b) ans = min(ans, index);
  }
  cout << ans + 1 << '\n';
  return 0;
}
