#include <bits/stdc++.h>
using namespace std;
int main() {
  long long S = 1;
  int i, j;
  int N, M;
  scanf("%d %d", &N, &M);
  vector<int> a(N);
  for (i = 0; i < N; i++) scanf("%d", &a[i]);
  if (N == 1) {
    cout << "0" << endl;
    return 0;
  }
  int avg = (a[0] + a[N - 1]) / 2;
  int upp = upper_bound(a.begin(), a.end(), avg) - a.begin(),
      low = lower_bound(a.begin(), a.end(), avg) - a.begin();
  int pos = N / 2;
  long long ans = 0;
  for (i = 0; i < pos; i += M) ans += a[pos] - a[i];
  for (i = N - 1; i > pos; i -= M) ans += a[i] - a[pos];
  ans *= 2;
  cout << ans << endl;
}
