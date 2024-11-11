#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e3 + 5;
const int MAX_VAL = 1e5 + 5;
int memo[MAX][MAX], arr[MAX], memo2[MAX];
vector<int> last[MAX_VAL], last_mod[8];
vector<int> adj[MAX];
int n;
int longest_path(int u) {
  int &ans = memo2[u];
  if (~ans) {
    return ans;
  }
  ans = 0;
  for (auto &each : adj[u]) {
    ans = max(ans, longest_path(each) + 1);
  }
  return ans;
}
int roll(int a, int b) {
  int &ans = memo[a][b];
  if (~ans) {
    return ans;
  }
  if (a > b) {
    swap(a, b);
  }
  ans = 0;
  bool none = true;
  for (auto &each : adj[a]) {
    if (each != b) {
      ans = max(ans, roll(each, b) + 1);
      none = false;
    }
  }
  if (none) {
    ans += longest_path(b);
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = int(1); i < int(n + 1); i++) {
    scanf("%d", arr + i);
  }
  for (int i = int(n); i >= int(1); i--) {
    for (auto &v : {last_mod[arr[i] % 7], last[arr[i] - 1], last[arr[i] + 1]}) {
      for (int j = int(v.size() - 1); j >= int(max(0, (int)v.size() - 3));
           j--) {
        adj[i].push_back(v[j]);
      }
    }
    last[arr[i]].push_back(i);
    last_mod[arr[i] % 7].push_back(i);
  }
  memset(memo, -1, sizeof memo);
  memset(memo2, -1, sizeof memo2);
  int ans = 0;
  for (int i = int(1); i < int(n + 1); i++) {
    for (int j = int(i + 1); j < int(n + 1); j++) {
      ans = max(ans, roll(i, j) + 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
