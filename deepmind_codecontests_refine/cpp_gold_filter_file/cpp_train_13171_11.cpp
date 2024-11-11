#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
const int MAXN = 200005;
int values[MAXN];
vector<int> adj[MAXN];
int values2[MAXN];
bool removed[MAXN];
int degrees[MAXN];
int N, K;
bool red[MAXN];
int dp[MAXN];
int maxx;
void dfs(int at) {
  maxa(maxx, values2[at]);
  removed[at] = true;
  int max1 = -1;
  int max2 = -1;
  dp[at] = values2[at];
  for (auto v : adj[at]) {
    if (!removed[v]) {
      dfs(v);
      maxa(dp[at], values2[at] + dp[v]);
      maxa(maxx, dp[at]);
      if (dp[v] >= max1) {
        max2 = max1;
        max1 = dp[v];
      } else {
        maxa(max2, dp[v]);
      }
    }
  }
  maxa(maxx, max1 + max2 + values2[at]);
}
bool good(int minimum) {
  for (int(i) = 0; (i) < (N); ++(i)) {
    values2[i] = 1;
    if (values[i] < minimum) {
      removed[i] = true;
    } else {
      removed[i] = false;
    }
    red[i] = false;
    dp[i] = 0;
  }
  queue<int> Q;
  for (int(i) = 0; (i) < (N); ++(i)) {
    if (removed[i]) continue;
    degrees[i] = 0;
    for (auto v : adj[i]) {
      if (!removed[v]) {
        degrees[i]++;
      } else {
        red[i] = true;
      }
    }
    if (degrees[i] == 0) {
      if (K == 1) {
        return true;
      }
    } else if (degrees[i] == 1 && !red[i]) {
      Q.push(i);
    }
  }
  maxx = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    removed[u] = true;
    maxa(maxx, values2[u]);
    for (auto v : adj[u]) {
      if (!removed[v]) {
        values2[v] += values2[u];
        maxa(maxx, values2[v]);
        degrees[v]--;
        if (!red[v] && degrees[v] == 1) {
          Q.push(v);
        }
      }
    }
  }
  for (int(i) = 0; (i) < (N); ++(i)) {
    if (!removed[i]) {
      dfs(i);
    }
  }
  return maxx >= K;
}
int main() {
  scanf("%d %d", &N, &K);
  for (int(i) = 0; (i) < (N); ++(i)) {
    scanf("%d", &values[i]);
  }
  for (int(i) = 0; (i) < (N - 1); ++(i)) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int left = 1, right = 1e6;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (good(mid)) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << right << endl;
  return 0;
}
