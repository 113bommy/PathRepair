#include <bits/stdc++.h>
using namespace std;
long long n, a[200001], c[200001];
pair<long long, long long> b[200001];
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  for (long long i = 0; i < n; i++) cin >> b[i].first, b[i].second = i;
  sort(b, b + n);
  for (long long i = 0; i < n; i++) {
    c[b[i].second] = a[i];
  }
  for (long long i = 0; i < n; i++) cout << c[i] << " " << endl;
  cout << endl;
  return 0;
}
