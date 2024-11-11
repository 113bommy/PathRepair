#include <bits/stdc++.h>
using namespace std;
int cnt[2][6];
void slv() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cnt[0][i % 5]++;
  for (int i = 1; i <= m; i++) cnt[1][i % 5]++;
  long long sum = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if ((i + j) % 5 == 0) sum += cnt[0][i] * cnt[1][j];
    }
  }
  cout << sum << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    slv();
  }
  return 0;
}
