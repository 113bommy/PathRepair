#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> &i, pair<long long, long long> &j) {
  return i.first > j.first;
}
const long double PI = acos(-1);
const long double EPS = 1e-9;
long long inf = 1e9 + 7;
long long n = 5e6 + 7;
long long mex(vector<long long> &arr) {
  long long n = arr.size();
  vector<bool> v(n, false);
  for (int i = 0; i < n; i++) {
    if (arr[i] < n) v[arr[i]] = true;
  }
  for (int i = 0; i < n; i++)
    if (!v[i]) return i;
  return n;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  vector<long long> arr;
  while (true) {
    long long k = mex(a);
    if (k >= n) break;
    a[k] = k;
    arr.push_back(k);
  }
  long long curr = 0;
  vector<long long> taken(n, 0);
  for (int i = 0; i < n; i++)
    if (a[i] == i) taken[i] = 1;
  while (curr < n) {
    if (taken[curr]) {
      curr++;
      continue;
    }
    if (curr >= n) break;
    vector<long long> temp;
    while (!taken[curr]) {
      taken[curr] = 1;
      arr.push_back(curr);
      curr = a[curr];
    }
    arr.push_back(curr);
  }
  cout << arr.size() << endl;
  for (auto x : arr) cout << x << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  k = 1;
  cin >> k;
  while (k--) solve();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
