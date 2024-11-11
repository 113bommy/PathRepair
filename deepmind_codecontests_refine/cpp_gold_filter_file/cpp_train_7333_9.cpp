#include <bits/stdc++.h>
using namespace std;
const int N = 10010, INF = 1000 * 100;
vector<long long> adj[N][2], ans, temp;
long long x, k, pt, divv[N], t;
int flag;
void solve(int p) {
  temp.clear();
  for (int i = 0; i < (int)adj[p][flag].size() && t < INF; i++) {
    long long u = adj[p][flag][i];
    int k = lower_bound(divv, divv + pt, u) - divv;
    for (int j = 0; j < (int)adj[k][flag].size() && t < INF; j++) {
      temp.push_back(adj[k][flag][j]);
      t++;
    }
  }
  flag = 1 - flag;
  adj[p][flag].clear();
  for (int i = 0; i < (int)temp.size(); i++) adj[p][flag].push_back(temp[i]);
  flag = 1 - flag;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> x >> k;
  if (k > INF) {
    if (x == 1) {
      cout << 1;
      return 0;
    }
    for (int i = 0; i < INF; i++) cout << "1 ";
    return 0;
  }
  if (k == 0) {
    cout << x;
    return 0;
  }
  long long s = sqrt(x);
  for (int i = 1; i <= s; i++) {
    if (x % i == 0) {
      divv[pt++] = i;
      ans.push_back(i);
      if (i != x / i) {
        divv[pt++] = x / i;
        ans.push_back(x / i);
      }
    }
  }
  sort(divv, divv + pt);
  sort(ans.begin(), ans.end());
  t = 0;
  for (int i = 0; i < pt && t < INF; i++) {
    for (int j = 0; j <= i && t < INF; j++) {
      if (divv[i] % divv[j] == 0 && t < INF) {
        adj[i][0].push_back(divv[j]);
        t++;
      }
    }
  }
  k--;
  while (k) {
    if (k % 2) {
      temp.clear();
      t = 0;
      for (int i = 0; i < (int)ans.size() && t < INF; i++) {
        int k = lower_bound(divv, divv + pt, ans[i]) - divv;
        for (int j = 0; j < (int)adj[k][flag].size() && t < INF; j++) {
          temp.push_back(adj[k][flag][j]);
          t++;
        }
      }
      ans.clear();
      for (int j = 0; j < (int)temp.size(); j++) ans.push_back(temp[j]);
    }
    k /= 2;
    t = 0;
    for (int i = 0; i < pt; i++) solve(i);
    flag = 1 - flag;
  }
  for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
}
