#include <bits/stdc++.h>
using namespace std;
const long long nMax = 1e5 + 5;
long long n;
pair<long long, long long> a[nMax];
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i].second;
  for (long long i = 1; i <= n; i++) cin >> a[i].first;
  sort(a + 1, a + n + 1);
  long long s = 0;
  for (long long i = 1; i <= n; i++) {
    s += a[i].second;
  }
  if (s <= a[n].first + a[n - 1].first) {
    cout << "YES";
  } else
    cout << "NO";
}
