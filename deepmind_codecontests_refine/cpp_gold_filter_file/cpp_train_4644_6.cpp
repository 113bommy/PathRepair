#include <bits/stdc++.h>
using namespace std;
const int ma = 28;
int num[ma];
int num2[ma];
int nd[8000000][2];
int p[8000000];
int cnt[8000000];
int currFree = 1;
void process(int val) {
  int curr = 0;
  for (int i = 0; i < ma; i++) {
    if (nd[curr][num[i]] == -1) {
      nd[curr][num[i]] = currFree;
      p[currFree] = curr;
      currFree++;
    }
    curr = nd[curr][num[i]];
  }
  while (curr != -1) {
    cnt[curr] += val;
    curr = p[curr];
  }
}
void go(int p, int val) {
  for (int i = 0; i < ma; i++) {
    num[i] = p & 1;
    p >>= 1;
  }
  reverse(num, num + ma);
  process(val);
}
int dfs(int v, int lev) {
  bool isRev = num[lev];
  int ans = 0;
  if (num2[lev] == 0) {
    if (isRev) {
      if (nd[v][1] != -1) ans += dfs(nd[v][1], lev + 1);
    } else {
      if (nd[v][0] != -1) ans += dfs(nd[v][0], lev + 1);
    }
  } else {
    if (isRev) {
      if (nd[v][1] != -1) ans += cnt[nd[v][1]];
      if (nd[v][0] != -1) ans += dfs(nd[v][0], lev + 1);
    } else {
      if (nd[v][1] != -1) ans += dfs(nd[v][1], lev + 1);
      if (nd[v][0] != -1) ans += cnt[nd[v][0]];
    }
  }
  return ans;
}
int count(int p, int l) {
  for (int i = 0; i < ma; i++) {
    num[i] = p & 1;
    p >>= 1;
  }
  reverse(num, num + ma);
  for (int i = 0; i < ma; i++) {
    num2[i] = l & 1;
    l >>= 1;
  }
  reverse(num2, num2 + ma);
  return dfs(0, 0);
}
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 8000000; i++) {
    p[i] = -1;
    cnt[i] = 0;
    for (int j = 0; j < ma; j++) {
      nd[i][j] = -1;
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int p;
      cin >> p;
      go(p, 1);
    } else if (typ == 2) {
      int p;
      cin >> p;
      go(p, -1);
    } else {
      int p, l;
      cin >> p >> l;
      cout << count(p, l) << "\n";
    }
  }
  return 0;
}
