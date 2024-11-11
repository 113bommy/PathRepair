#include <bits/stdc++.h>
using namespace std;
const long long N = 105;
struct exam {
  long long s, d, c, idx;
};
long long n, m;
exam arr[N];
bool comp(exam& a, exam& b) { return a.d < b.d; }
long long ans[N];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> arr[i].s >> arr[i].d >> arr[i].c;
    arr[i].idx = i;
    ans[arr[i].d] = m + 1;
  }
  sort(arr + 1, arr + m + 1, comp);
  for (long long i = 1; i <= m; i++) {
    long long start = arr[i].s;
    long long rqrd = arr[i].c;
    for (long long j = start; j < arr[i].d; j++) {
      if (ans[j] > 0 || rqrd == 0) continue;
      ans[j] = arr[i].idx;
      rqrd--;
    }
    if (rqrd > 0) {
      cout << -1;
      return 0;
    }
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
