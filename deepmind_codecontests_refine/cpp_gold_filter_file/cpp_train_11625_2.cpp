#include <bits/stdc++.h>
using namespace std;
const int MOD = 95542721;
const int INF = 2e9;
const long long INF64 = 4e18;
const long double EPS = 1e-16;
const long long MD = 1551513443;
const long long T = 2543;
const int N = 300010;
const int M = 100;
const int DEBUG = 0;
const int MAGIC = 320;
int n;
long long ans;
vector<int> g[N];
vector<int> dp[N];
vector<long long> *dp_ans[N];
multiset<int> s[N];
void push_max(pair<int, int> &a, int first) {
  if (first > a.second) {
    a.second = first;
    if (a.second > a.first) swap(a.first, a.second);
  }
}
void dfs(int v, int p) {
  int k = int((g[v]).size()) - 1;
  if (p == -1) k = int((g[v]).size());
  if (k == 0) {
    dp[v].resize(2, 1);
    dp_ans[v] = new vector<long long>(2, 1);
    ans += n;
    return;
  } else {
    dp[v].resize(k + 1, 2);
    dp_ans[v] = new vector<long long>;
  }
  pair<int, int> maxi2 = {1, 1};
  int ind = -1, maxi = 0;
  for (int u : g[v])
    if (u != p) {
      dfs(u, v);
      push_max(maxi2, int((dp[u]).size()) - 1);
      if (int(dp_ans[u]->size()) > maxi) {
        maxi = int(dp_ans[u]->size());
        ind = u;
      }
    }
  k = min(k, maxi2.second);
  for (int i = 0; i < int(k + 1); i++) s[i].clear();
  for (int u : g[v])
    if (u != p) {
      for (int i = 1; i <= min(k, int((dp[u]).size()) - 1); i++) {
        s[i].insert(-dp[u][i]);
        if (s[i].size() > i) {
          multiset<int>::iterator it = s[i].end();
          it--;
          s[i].erase(it);
        }
      }
    }
  for (int i = 1; i <= k; i++)
    if (s[i].size() == i) dp[v][i] = max(dp[v][i], -(*s[i].rbegin()) + 1);
  dp_ans[v] = dp_ans[ind];
  for (int i = 1; i < int((dp[v]).size()); i++) {
    if (i >= dp_ans[v]->size()) {
      dp_ans[v]->push_back(dp[v][i]);
      (*dp_ans[v])[0] += dp[v][i];
    } else {
      long long first = dp[v][i];
      if (first > (*dp_ans[v])[i]) {
        (*dp_ans[v])[0] -= (*dp_ans[v])[i];
        (*dp_ans[v])[i] = first;
        (*dp_ans[v])[0] += first;
      }
    }
  }
  for (int u : g[v])
    if (u != p && u != ind) {
      for (int i = 1; i < dp_ans[u]->size(); i++) {
        long long first = (*dp_ans[u])[i];
        if (first > (*dp_ans[v])[i]) {
          (*dp_ans[v])[0] -= (*dp_ans[v])[i];
          (*dp_ans[v])[i] = first;
          (*dp_ans[v])[0] += first;
        }
      }
    }
  int m = dp_ans[v]->size() - 1;
  ans += (*dp_ans[v])[0];
  ans += n - m;
}
int main() {
  cin >> n;
  for (int i = 0; i < int(n - 1); i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    g[first].push_back(second);
    g[second].push_back(first);
  }
  dfs(1, -1);
  cout << ans << endl;
  return 0;
}
