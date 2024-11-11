#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
vector<int> fri[maxn];
long long n, m;
int l, r;
int sum;
bool p[maxn];
bool q[maxn];
void dfs(int num) {
  sum++;
  q[num] = 1;
  int len = fri[num].size();
  for (int i = 0; i < len; i++) {
    int to = fri[num][i];
    if (!q[to]) dfs(to);
  }
}
void check(int num) {
  p[num] = 1;
  int len = fri[num].size();
  if (len < sum - 1) {
    cout << "NO";
    exit(0);
  }
  for (int i = 0; i < len; i++) {
    int to = fri[num][i];
    if (!p[to]) check(to);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> l >> r;
    fri[l].push_back(r);
    fri[r].push_back(l);
  }
  for (int i = 1; i <= n; i++) {
    if (!p[i]) {
      sum = 0;
      dfs(i);
      check(i);
    }
  }
  cout << "YES";
  return 0;
}
