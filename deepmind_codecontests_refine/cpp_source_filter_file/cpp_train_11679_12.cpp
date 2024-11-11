#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  pair<long long, long long> a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i * 2 + 1;
  }
  sort(a, a + n, less<pair<long long, long long> >());
  long long large[2 * n + 1];
  large[0] = a[0].second;
  for (long long i = 1; i < n; i++) {
    cout << a[i].second << ' ' << a[i - 1].second << endl;
    large[i] = a[i].second;
  }
  for (long long i = 0; i < n; i++) {
    long long ind = i + a[i].first - 1;
    cout << a[i].second + 1 << ' ' << large[ind] << endl;
    if (ind + 1 >= n) large[ind + 1] = a[i].second + 1;
  }
}
