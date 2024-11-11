#include <bits/stdc++.h>
using namespace std;
const long long inf = 4e18;
const long long maxn = 3e5 + 10;
#pragma GCC Optimize("Ofast")
long long d[maxn];
bool no[maxn];
int main() {
  long long n, k, tot = 0;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 2 * i; j <= n; j += i) {
      d[j]++;
      tot++;
    }
  }
  if (k > tot) {
    cout << "No";
    return 0;
  }
  if (k == 3) {
    cout << "Yes\n";
    cout << 3 << endl << 1 << " " << 2 << " " << 4;
    return 0;
  }
  if (k == 6) {
    cout << "Yes\n";
    cout << 5 << endl << 1 << " " << 2 << " " << 4 << " " << 5 << " " << 6;
    return 0;
  }
  while ((tot - d[n]) >= k) {
    tot -= d[n--];
  }
  vector<pair<long long, long long> > v;
  v.clear();
  long long i = n;
  while (i > (n / 2)) {
    v.push_back(make_pair(d[i], i));
    i--;
  }
  sort(v.begin(), v.end(), greater<pair<long long, long long> >());
  i = 0;
  tot = tot - k;
  while (tot > 0 && i < (v).size()) {
    if (v[i].first <= tot) {
      tot -= v[i].first;
      no[v[i].second] = 1;
    }
    i++;
  }
  long long SZ = 0;
  cout << "Yes\n";
  for (long long i = 1; i <= n; i++)
    if (!no[i]) SZ++;
  cout << SZ << endl;
  for (long long i = 1; i <= n; i++)
    if (!no[i]) cout << i << " ";
}
