#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  map<string, int> word;
  vector<int> cost(n), group(n);
  vector<int> gmin(k, -1);
  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    word[w] = i;
  }
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    cost[i] = c;
  }
  for (int i = 0; i < k; i++) {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int w;
      cin >> w;
      w--;
      group[w] = i;
      if (gmin[i] == -1 || gmin[i] > cost[w]) gmin[i] = cost[w];
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    string w;
    cin >> w;
    ans += gmin[group[word[w]]];
  }
  cout << ans;
}
