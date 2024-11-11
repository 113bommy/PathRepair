#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> x(m, 0);
  for (int i = 0; i < m; i++) cin >> x[i];
  long long sum = 0;
  for (int i = 0; i < m - 1; i++) sum += abs(x[i] - x[i + 1]);
  cout << sum << " ";
  vector<int> cnt(n + 1, 0);
  for (int i = 0; i < m - 1; i++) {
    if (abs(x[i] - x[i + 1]) > 1) {
      cnt[min(x[i], x[i + 1]) + 1]++;
      cnt[max(x[i], x[i + 1])]--;
    }
  }
  for (int i = 2; i <= n; i++) cnt[i] += cnt[i - 1];
  vector<vector<int> > adj(n + 1);
  for (int i = 0; i < m - 1; i++) {
    if (x[i] != x[i + 1]) {
      adj[x[i]].push_back(x[i + 1]);
      adj[x[i + 1]].push_back(x[i]);
    }
  }
  for (int i = 2; i <= n; i++) {
    long long sum2 = sum - cnt[i];
    for (auto j : adj[i]) {
      sum2 -= abs(j - i);
      if (j > i)
        sum2 += j - 1;
      else
        sum2 += j;
    }
    cout << sum2 << " ";
  }
  cout << endl;
  return 0;
}
