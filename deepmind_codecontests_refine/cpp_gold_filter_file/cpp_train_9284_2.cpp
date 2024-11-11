#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t clk = clock();
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    s.push_back('X');
    int n = s.size();
    int pos[n + 1];
    pos[0] = -1;
    for (int i = 1; i <= n; i++)
      pos[i] = (s[i - 1] == 'X') ? (i - 1) : pos[i - 1];
    vector<int> total_gap;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'X') {
        int gapp = pos[i + 1] - pos[i] - 1;
        if (gapp) total_gap.push_back(gapp);
      }
    }
    int total_a = 0, total_b = 0;
    int max1 = 0;
    for (int i = 0; i < total_gap.size(); i++) {
      if (total_gap[i] < b) continue;
      if (total_gap[i] < a) goto lose;
      total_a++;
      if (total_gap[i] >= 2 * b) total_b++;
      max1 = max(max1, total_gap[i]);
    }
    if (total_b == 0) {
      if (total_a % 2 == 1)
        goto win;
      else
        goto lose;
    }
    if (total_b >= 2) goto lose;
    for (int i = 0; i + a <= max1; i++) {
      int l = i;
      int r = max1 - a - i;
      if (l >= 2 * b || r >= 2 * b || (l >= b && l < a) || (r >= b && r < a))
        continue;
      int cnt = (l >= a) + (r >= a);
      if ((total_a + cnt) % 2 == 1) goto win;
    }
    goto lose;
  win:
    cout << "YES" << endl;
    continue;
  lose:
    cout << "NO" << endl;
  }
  cerr << endl
       << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
  return 0;
}
