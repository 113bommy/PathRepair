#include <bits/stdc++.h>
using namespace std;
long long diff[300000], arrx1[300000], arrx2[300000], cur, dist, mx = -1, n, h,
                                                                 x1, x2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> h;
  vector<long long> summ(n);
  for (int i = 0; i < n; i++) {
    cin >> x1 >> x2;
    arrx1[i] = x1;
    arrx2[i] = x2;
    if (i)
      diff[i] = x1 - arrx2[i - 1];
    else
      diff[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (i)
      summ[i] = diff[i] + summ[i - 1];
    else
      summ[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cur = h + summ[i];
    auto it = lower_bound(summ.begin(), summ.end(), cur);
    int idx = (it - summ.begin());
    if (it == summ.end() || summ[idx] >= cur) idx--;
    cur -= summ[idx];
    dist = arrx2[idx] - arrx1[i] + cur;
    mx = max(dist, mx);
  }
  cout << mx << endl;
  return 0;
}
