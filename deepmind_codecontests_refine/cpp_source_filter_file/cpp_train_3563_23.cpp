#include <bits/stdc++.h>
using namespace std;
const int MAXN = 85;
const int MAXK = 15;
const int inf = 1e9 + 5;
int n, k;
int a[MAXN][MAXN];
int answer = inf;
vector<pair<int, int>> transition[MAXN][MAXN];
int usedNodes[MAXN];
vector<int> seq;
void init() {
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      for (int z = 1; z <= n; z++) {
        if (z == x || z == y) continue;
        transition[x][y].push_back({a[x][z] + a[z][y], z});
      }
      sort(transition[x][y].begin(), transition[x][y].end());
    }
  }
}
int getTransition(int x, int y) {
  for (pair<int, int> item : transition[x][y]) {
    if (usedNodes[item.second] == 0) return item.first;
  }
  return -1;
}
void getPart0(int taken) {
  if (taken == k / 2) {
    int curr = 0;
    for (int i = 1; i < seq.size(); i++)
      curr += getTransition(seq[i - 1], seq[i]);
    curr += getTransition(seq.back(), 1);
    answer = min(answer, curr);
    return;
  }
  for (int x = 1; x <= n; x++) {
    usedNodes[x]++;
    seq.push_back(x);
    getPart0(taken + 1);
    usedNodes[x]--;
    seq.pop_back();
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  init();
  seq = {1};
  usedNodes[1]++;
  getPart0(1);
  cout << answer << '\n';
}
