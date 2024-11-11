#include <bits/stdc++.h>
using namespace std;
vector<long long> v[1000000];
int main() {
  long long n, k, m, i;
  cin >> n >> k >> m;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    long long x = a[i] % m;
    if (v[x].size() < k) v[x].push_back(a[i]);
  }
  for (i = 0; i < n; i++) {
    if (v[i].size() >= k) {
      cout << "Yes\n";
      for (long long j = 0; j < k; j++) {
        cout << v[i][j] << " ";
      }
      return 0;
    }
  }
  cout << "No";
}
