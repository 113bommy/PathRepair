#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int n, m;
  cin >> n >> m;
  int dbt[101] = {0};
  int a, b, c;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b >> c;
    dbt[a] -= c;
    dbt[b] += c;
  }
  int ans = 0;
  for (long long i = 0; i < n + 1; i++) {
    if (dbt[i] < 0) ans -= dbt[i];
  }
  cout << ans << endl;
  return 0;
}
