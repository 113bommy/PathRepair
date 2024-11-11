#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  tuple<long long, long long, long long> arr[n - 1];
  long long s1, e1;
  cin >> s1 >> e1;
  for (long long i = 0; i < n - 1; ++i) {
    long long s2, e2;
    cin >> s2 >> e2;
    arr[i] = make_tuple(e2 - s1 + 1, s2 - e1 - 1, i);
    s1 = s2, e1 = e2;
  }
  pair<long long, long long> blen1[m];
  long long blen2[m];
  for (long long i = 0; i < m; ++i) {
    long long b;
    cin >> b;
    blen1[i] = make_pair(b, i);
    blen2[i] = b;
  }
  sort(arr, arr + n - 1);
  sort(blen1, blen1 + m);
  sort(blen2, blen2 + m);
  pair<long long, long long> num_b[n - 1];
  for (long long i = 0; i < n - 1; ++i) {
    long long end, start, idx, u = 0, l = 0;
    tie(end, start, idx) = arr[i];
    l = upper_bound(blen2, blen2 + m, start) - blen2;
    u = lower_bound(blen2, blen2 + m, end) - blen2;
    if (u - l == 0) {
      cout << "No" << endl;
      return 0;
    } else {
      num_b[i] = make_pair(l, u);
    }
  }
  set<pair<long long, long long> > bg;
  for (long long i = 0; i < m; ++i) {
    bg.insert(blen1[i]);
  }
  long long ans[n - 1];
  for (long long i = 0; i < n - 1; ++i) {
    long long u = num_b[i].second, l = num_b[i].first;
    set<pair<long long, long long> >::iterator itr =
        bg.upper_bound({blen2[l], -1});
    if (itr == bg.end() || (u != m && (*itr).first >= blen2[u])) {
      cout << "No" << endl;
      return 0;
    }
    ans[get<2>(arr[i])] = (*itr).second + 1;
    bg.erase(itr);
  }
  cout << "Yes" << endl;
  for (long long i = 0; i < n - 1; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
