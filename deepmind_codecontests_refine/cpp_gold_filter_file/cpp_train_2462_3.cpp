#include <bits/stdc++.h>
using namespace std;
int n, cnt = 1;
vector<vector<int>> a;
vector<int> b;
void dfs(int x, int dst) {
  b[dst]++;
  for (auto y : a[x]) dfs(y, dst + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  a.resize(n + 1);
  b.resize(n);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  dfs(1, 0);
  int sum = 0;
  for (auto x : b) sum += x % 2;
  cout << sum;
}
