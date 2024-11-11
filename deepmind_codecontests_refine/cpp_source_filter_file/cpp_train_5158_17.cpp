#include <bits/stdc++.h>
using namespace std;
void make_unique(vector<long long> vec) {
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    long long x, k, h, p, a, b, c, t, n, m, i, j, flag = 0, count = 0, move = 0;
    cin >> n >> m;
    if (n > m) swap(n, m);
    for (i = 0; i < n; i++) {
      count += (m + (i % 5)) / 5;
    }
    cout << count << '\n';
  }
  return 0;
}
