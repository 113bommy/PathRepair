#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> r(m, (int)1e7);
  int t, d;
  for (int i = 0; i < n; i++) {
    cin >> t >> d;
    r[t - 1] = min(r[t - 1], d);
  }
  int answer = 0;
  for (int i = 0; i < m; i++) {
    answer += r[i];
  }
  cout << min(answer, k);
}
