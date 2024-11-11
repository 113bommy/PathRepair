#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[100000 + 10];
long long b[100000 + 10];
long long c[100000 + 10];
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  a[n + 1].first = 0;
  sort(a + 1, a + n + 1);
  long long minn = 10000000;
  for (long long i = 1; i <= n; i++) {
    c[a[i].first]++;
  }
  for (long long i = 2; i <= n; i++)
    if (c[i] > c[i - 1]) {
      cout << -1;
      return 0;
    }
  long long cc = 2;
  b[a[1].second] = 1;
  cout << c[1] << endl;
  for (long long i = 2; i <= n; i++) {
    if (a[i].first != a[i - 1].first) cc = 1;
    b[a[i].second] = cc;
    cc++;
  }
  for (long long i = 1; i <= n; i++) cout << b[i] << " ";
}
