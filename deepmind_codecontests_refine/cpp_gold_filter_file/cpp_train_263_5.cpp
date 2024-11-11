#include <bits/stdc++.h>
using namespace std;
const long long nmax = 202;
int main() {
  long long n;
  pair<long long, long long> a[nmax];
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    sort(a, a + i);
    long long s, e;
    cin >> s >> e;
    e = s + e - 1;
    bool ok = 1;
    for (long long j = 1; j < i; j++)
      if (a[j].second >= s && a[j].first <= e) ok = 0;
    if (ok) {
      cout << (a[i].first = s) << " " << (a[i].second = e) << endl;
      continue;
    }
    a[i].first = 1000000000000000;
    for (long long j = 0; j < i; j++)
      if (a[j + 1].first - a[j].second - 1 >= e - s + 1) {
        cout << (a[i].first = a[j].second + 1) << " "
             << (a[i].second = a[j].second + e - s + 1) << endl;
        break;
      }
  }
}
