#include <bits/stdc++.h>
using namespace std;
vector<int> ary;
set<int> st;
int par[100];
int k, n;
void print(int v) {
  queue<int> que;
  while (v != par[v]) {
    que.push(v);
    v = par[v];
  }
  que.push(v);
  cout << que.size() << " ";
  while (!que.empty()) {
    cout << ary[que.front()] << " ";
    que.pop();
  }
  cout << endl;
  k--;
  if (k == 0) exit(0);
}
void dfs(int v, int p, int sum) {
  if (st.find(sum) != st.end()) return;
  par[v] = p;
  print(v);
  st.insert(sum);
  for (int i = v + 1; i <= n; i++) dfs(i, v, sum + ary[i]);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    ary.push_back(a);
  }
  sort(ary.begin(), ary.end(), greater<int>());
  for (int i = 0; i < n; i++) dfs(i, i, ary[i]);
  return 0;
}
