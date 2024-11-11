#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k * (k - 1) < n) {
    cout << "NO";
    return 0;
  }
  vector<pair<long long, long long> > pair;
  cout << "YES\n";
  long long cnt = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      cout << i << " " << j << '\n';
      cnt++;
      if (cnt >= n) return 0;
      cout << j << " " << i << '\n';
      cnt++;
      if (cnt >= n) return 0;
    }
  }
  return 0;
}
