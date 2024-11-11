#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long n, m, ans = 0;
  cin >> n >> m;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<pair<long long, long long> > que(m);
  for (long long i = 0; i < m; i++) {
    cin >> que[i].first >> que[i].second;
    que[i].first--;
    que[i].second--;
  }
  long long opt1, opt2;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      long long n1 = 0, n2 = 0;
      for (long long k = 0; k < m; k++) {
        if ((que[k].first <= i && que[k].second >= i) &&
            (j < que[k].first || j > que[k].second))
          n2++;
        if ((que[k].first <= j && que[k].second >= j) &&
            (i < que[k].first || i > que[k].second))
          n1++;
      }
      if (ans < a[i] - a[j] + n1) {
        opt1 = i;
        opt2 = j;
        ans = a[i] - a[j] + n1;
      }
      if (ans < a[j] - a[i] + n2) {
        opt1 = j;
        opt2 = i;
        ans = a[j] - a[i] + n2;
      }
    }
  }
  vector<long long> taken;
  for (long long i = 0; i < m; i++) {
    pair<long long, long long> x = que[i];
    if ((opt2 >= x.first && opt2 <= x.second) &&
        (opt1 < x.first || opt1 > x.second))
      taken.push_back(i + 1);
  }
  cout << ans << "\n" << taken.size() << endl;
  for (auto x : taken) cout << x << " ";
  cout << endl;
}
