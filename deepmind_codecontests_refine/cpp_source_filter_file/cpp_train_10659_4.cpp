#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
int cross(int a1, int b1, int a2, int b2) { return (a1 * b2 - a2 * b1); }
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  return cross(b.first - a.first, b.second - a.second, c.first - a.first,
               c.second - a.second);
}
void hi() { printf("hi\n"); }
int parents[100010];
int myrank[100010];
void init() { memset(parents, -1, sizeof(parents)); }
int ancestor(int a) {
  if (parents[a] == -1) {
    return a;
  }
  parents[a] = ancestor(parents[a]);
  return parents[a];
}
bool merge(int a, int b) {
  a = ancestor(a);
  b = ancestor(b);
  if (a == b) return false;
  if (myrank[a] > myrank[b]) {
    parents[b] = a;
  } else if (myrank[a] == myrank[b]) {
    parents[b] = a;
    myrank[a]++;
  } else {
    parents[a] = b;
  }
  return true;
}
int n, x;
bool dp[1010][1010];
vector<int> sizes;
int goesto[1010];
int xplace = 1;
int main() {
  init();
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> goesto[i];
    goesto[i]--;
    if (goesto[i] != -1) {
      merge(goesto[i], i);
    }
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (ancestor(j) == i) {
        if (j == x) {
          cnt = 0;
          break;
        }
        cnt++;
      }
    }
    if (cnt) {
      sizes.push_back(cnt);
    }
  }
  int xcpy = x - 1;
  while (goesto[xcpy] != -1) {
    xplace++;
    xcpy = goesto[xcpy];
  }
  dp[0][xplace] = 1;
  for (int i = 1; i <= sizes.size(); i++) {
    for (int p = 1; p <= n; p++) {
      dp[i][p] = dp[i - 1][p];
      if (p > sizes[i - 1]) {
        dp[i][p] = dp[i][p] || dp[i - 1][p - sizes[i - 1]];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dp[sizes.size()][i]) {
      cout << i << endl;
    }
  }
  return 0;
}
