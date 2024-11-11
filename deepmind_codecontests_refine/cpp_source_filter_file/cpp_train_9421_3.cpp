#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
bool mark[maxn], markk[maxn];
vector<int> ans;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n * n; i++) {
    int x, v;
    cin >> x >> v;
    if (mark[x] or mark[v]) continue;
    ans.push_back(i);
    mark[x] = true, markk[v] = true;
  }
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
