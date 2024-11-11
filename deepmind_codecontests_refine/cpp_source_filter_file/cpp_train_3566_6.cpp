#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e18 + 1;
bool sortbyse(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long finds(vector<long long> v, long long n) {
  long long x = 0, mx = 0;
  for (long long i = 0; i < n; i++) {
    x += v[i];
    if (x < 0) x = 0;
    mx = max(mx, x);
  }
  return mx;
}
void solve() {
  long long n;
  cin >> n;
  long long ar[n], sum = 0;
  vector<long long> v1, v2;
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
    if (i % 2 == 0) sum += ar[i];
  }
  for (long long i = 1; i < n; i += 2) {
    v1.push_back(ar[i] - ar[i - 1]);
  }
  for (long long i = 1; i < n - 1; i++) {
    v2.push_back(ar[i] - ar[i + 1]);
  }
  long long x = finds(v1, v1.size());
  long long y = finds(v2, v2.size());
  sum += max(x, y);
  cout << sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  q = 1;
  cin >> q;
  while (q--) {
    solve();
    cout << endl;
  }
  return 0;
}
