#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10, maxm = (1 << 17), mod = 1e9 + 7, hash = 701;
const double PI = 3.14159265359, E = 2.71828;
long long a[maxn];
pair<long long, long long> d[maxn];
int main() {
  ios::sync_with_stdio(0);
  long long n, sum;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    sum = a[i], d[i] = make_pair((1 << 30), (1 << 30));
    for (int j = i - 1; j >= 0; j--) {
      if (sum >= d[j].second) {
        if (d[j].first + i - j - 1 < d[i].first)
          d[i].first = d[j].first + i - j - 1;
        if (d[i].first == d[j].first + i - j - 1)
          d[i].second = min(d[i].second, sum);
      }
      sum += a[j];
    }
  }
  cout << d[n].first << endl;
  return 0;
}
