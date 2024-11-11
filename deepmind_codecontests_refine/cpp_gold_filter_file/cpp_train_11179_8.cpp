#include <bits/stdc++.h>
using namespace std;
int n, k, ans[25][10 * 1000 + 10];
vector<int> p;
set<int> s;
int main() {
  ios ::sync_with_stdio(0);
  cin >> n >> k;
  for (int cur = 1; cur <= n; cur *= 2) {
    p.push_back(cur);
    s.insert(cur);
  }
  for (int i = 0; i < p.size(); i++) {
    for (int j = 0; j < i; j++) ans[j][p[i]] = p[i];
    for (int j = i; j < k; j++) ans[j][p[i]] = 0;
  }
  for (int i = 1; i < n; i++)
    if (s.find(i) == s.end()) {
      ans[0][i] = 0;
      for (int j = 0; j < k; j++)
        if ((i - 1) & (1 << j))
          ans[j][i] = 1 << j;
        else
          ans[j][i] = 0;
    }
  for (int i = 0; i < k; i++, cout << endl)
    for (int j = n - 1; j >= 0; j--) cout << n - ans[i][j] << ' ';
}
