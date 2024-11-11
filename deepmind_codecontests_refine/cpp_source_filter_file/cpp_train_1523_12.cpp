#include <bits/stdc++.h>
using namespace std;
const int N = ((5 * (1e3)) + 10), mod = 1e9 + 7;
int mark[N], ar[N][2], n, ans;
vector<int> mj[N];
bool k;
long long pw(int a, int b) {
  int ja = 1;
  for (int i = 0; i < b; i++) {
    ja *= a;
    ja %= mod;
  }
  if (ja < 0) {
    ja += mod;
  }
  return ja;
}
void dfs(int v, int c) {
  mark[v] = c;
  for (int i = 0; i < mj[v].size(); i++) {
    if (mark[mj[v][i]] == c) {
      k = 1;
      return;
    } else if (mark[mj[v][i]] == 3 - c) {
      continue;
    } else if (!mark[mj[v][i]])
      dfs(mj[v][i], 3 - c);
  }
  return;
}
bool bipartite(int x) {
  for (int i = 0; i < n; i++) {
    mj[i].clear();
    mark[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int sumx = abs(ar[i][0] - ar[j][0]);
      int sumy = abs(ar[i][1] - ar[j][1]);
      if (sumx + sumy > x) {
        mj[i].push_back(j);
        mj[j].push_back(i);
      }
    }
  }
  k = 0;
  ans = 0;
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      dfs(i, 1);
      ans++;
    }
    if (k == 1) return false;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i][0] >> ar[i][1];
  }
  int st = -1, ed = N - 10;
  while (ed - st > 1) {
    int mid = (ed + st) / 2;
    if (bipartite(mid))
      ed = mid;
    else
      st = mid;
  }
  ans = 0;
  bipartite(ed);
  long long j = pw(2, ans);
  cout << ed << endl << j;
}
