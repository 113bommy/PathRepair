#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int maxn = 100000 + 10;
const int inf = 1000000000;
ifstream fin("input.txt");
ofstream fout("output.txt");
int n, ans, t;
pair<int, int> p[maxn];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    for (int j = 1; 1; j++)
      if (1ll << (2 * j) >= p[i].second) {
        ans = max(ans, j + p[i].first);
        break;
      }
  }
  cout << ans << endl;
  return 0;
}
