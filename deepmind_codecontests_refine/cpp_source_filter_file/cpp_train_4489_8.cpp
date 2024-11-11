#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> adia[N];
int sp[N], si[N], np[N], ni[N];
long long asp, asi, anp, ani;
void dfs(int nod, int t) {
  np[nod] = 1;
  for (auto i : adia[nod]) {
    if (i == t) continue;
    dfs(i, nod);
    asp += ni[i] * sp[nod] + np[nod] * (si[i] + ni[i]) + np[i] * si[nod] +
           (sp[i] + np[i]) * ni[nod];
    asi += np[i] * sp[nod] + (sp[i] + np[i]) * np[nod] + si[nod] * ni[i] +
           ni[nod] * (si[i] + ni[i]);
    ani += ni[nod] * ni[i] + np[nod] * np[i];
    sp[nod] += si[i] + ni[i];
    si[nod] += sp[i] + np[i];
    np[nod] += ni[i];
    ni[nod] += np[i];
  }
}
int main() {
  int n, a, b;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    adia[a].push_back(b);
    adia[b].push_back(a);
  }
  dfs(1, 0);
  cout << asp / 2 + (asi + ani) / 2;
  return 0;
}
