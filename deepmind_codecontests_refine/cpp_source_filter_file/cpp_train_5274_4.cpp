#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int u;
  cin >> n >> u;
  vector<int> e(n);
  for (int i = 0; i < n; i++) cin >> e[i];
  double maxi = -1;
  for (int i = 0; i < n; i++) {
    int nextpos = i + 1;
    int finalpos = upper_bound(e.begin(), e.end(), e[i] + u) - e.begin();
    finalpos--;
    if (finalpos < nextpos) continue;
    maxi = max(maxi, (double)(e[finalpos] - e[nextpos]) / (e[finalpos] - e[i]));
  }
  cout << fixed << setprecision(20) << maxi << endl;
}
