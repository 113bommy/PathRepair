#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 12;
const int ACU = 100;
pair<pair<long long, long long>, long long> d[N];
long long n, k, h, mass[N];
long long g(long long i, long double t) { return (t * d[i].first.second) / h; }
bool pos(int i, long double t, int ind) { return g(i, t) >= ind; }
bool check(long double t) {
  int todo = k;
  for (int i = n - 1; todo && i > -1; i--)
    if (pos(i, t, todo)) todo--;
  return !todo;
}
bool cmp(int a, int b) { return mass[a] < mass[b]; }
int32_t main() {
  cin >> n >> k >> h;
  for (int i = 0; i < n; i++) cin >> d[i].first.first;
  for (int i = 0; i < n; i++) cin >> d[i].first.second;
  for (int i = 0; i < n; i++) d[i].second = i;
  for (int i = 0; i < n; i++) mass[i] = d[i].first.first;
  sort(d, d + n);
  long double Lo = 0;
  long double Hi = 1e9 + 7;
  for (int i = 0; i < ACU; i++)
    if (check((Hi + Lo) / 2.))
      Hi = (Hi + Lo) / 2.;
    else
      Lo = (Hi + Lo) / 2.;
  cerr << Hi << endl;
  vector<long long> ans;
  int todo = k;
  for (int i = n - 1; todo && i > -1; i--)
    if (pos(i, Hi, todo)) {
      ans.push_back(d[i].second);
      todo--;
    }
  for (int i = k - 1; i > -1; i--) cout << ans[i] + 1 << ' ';
}
