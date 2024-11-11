#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int x[100001], y[100001], id[100001];
int pow2[100001];
int usedX[100001], usedY[100001], xnum, ynum, cnt;
bool used[100001];
vector<int> v[100001];
bool cmpX(int i, int j) { return x[i] < x[j]; }
bool cmpY(int i, int j) { return y[i] < y[j]; }
void dfs(int i) {
  used[i] = true;
  cnt++;
  usedX[xnum++] = x[i];
  usedY[ynum++] = y[i];
  for (int j : v[i]) {
    if (!used[j]) dfs(j);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    id[i] = i;
  }
  sort(id, id + n, cmpX);
  for (int i = 1; i < n; i++) {
    if (x[id[i]] == x[id[i - 1]]) {
      v[id[i]].push_back(id[i - 1]);
      v[id[i - 1]].push_back(id[i]);
    }
  }
  sort(id, id + n, cmpY);
  for (int i = 1; i < n; i++) {
    if (y[id[i]] == y[id[i - 1]]) {
      v[id[i]].push_back(id[i - 1]);
      v[id[i - 1]].push_back(id[i]);
    }
  }
  int ans = 1;
  pow2[0] = 1;
  for (int i = 1; i <= n + 1; i++) pow2[i] = pow2[i - 1] * 2 % mod;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      xnum = 0;
      ynum = 0;
      cnt = 0;
      dfs(i);
      sort(usedX, usedX + xnum);
      sort(usedY, usedY + ynum);
      int sum = unique(usedX, usedX + xnum) - usedX +
                unique(usedY, usedY + ynum) - usedY;
      ans = (long long)ans * (pow2[sum] - (sum > cnt ? 1 : 0));
    }
  }
  printf("%d\n", ans);
}
