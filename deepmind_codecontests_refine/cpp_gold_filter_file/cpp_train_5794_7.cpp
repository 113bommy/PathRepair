#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    v[i] -= 1;
  }
  vector<long long int> vys(n);
  for (long long int i = 0; i < n; i++) {
    if (v[i] == -1) {
      long long int lavy;
      lavy = max(0ll, i - k);
      long long int pravy = min(n - 1, i + k);
      vys[i] = pravy - lavy + 1;
    } else {
      long long int rodic = v[i];
      long long int p = min(n - 1, rodic + k);
      long long int now = min(n - 1, i + k);
      long long int pred = vys[rodic];
      long long int pravy = min(n - 1, i + k);
      long long int lavy = max(0ll, i - k);
      vys[i] = min(now - p, pravy - lavy + 1) + pred;
    }
  }
  for (long long int i = 0; i < n; i++) {
    cout << vys[i] << ' ';
  }
  cout << '\n';
  return 0;
}
