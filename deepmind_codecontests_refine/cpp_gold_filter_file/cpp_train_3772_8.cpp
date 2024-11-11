#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 90;
int n, m, a[N], b[N], ans[20], t[N];
set<int> d[3][2 * N], s[N], r[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    r[a[i]].insert(b[i]);
    s[b[i]].insert(a[i]);
    int k = a[i] - b[i] + n - 1;
    d[0][k].insert(a[i]);
    k = a[i] + b[i];
    d[1][k].insert(a[i]);
  }
  for (int i = 0; i < m; i++) {
    set<int>::iterator itb = r[a[i]].begin();
    set<int>::iterator ite = r[a[i]].end();
    ite--;
    if ((b[i] == *itb or b[i] == *ite) and r[a[i]].size() != 1) t[i]++;
    if (b[i] != *itb and b[i] != *ite and r[a[i]].size() != 1) t[i] += 2;
    itb = s[b[i]].begin();
    ite = s[b[i]].end();
    ite--;
    if ((a[i] == *itb or a[i] == *ite) and s[b[i]].size() != 1) t[i]++;
    if ((a[i] != *itb and a[i] != *ite) and s[b[i]].size() != 1) t[i] += 2;
    int k = a[i] - b[i] + n - 1;
    itb = d[0][k].begin();
    ite = d[0][k].end();
    ite--;
    if ((a[i] == *itb or a[i] == *ite) and d[0][k].size() != 1) t[i]++;
    if ((a[i] != *itb and a[i] != *ite) and d[0][k].size() != 1) t[i] += 2;
    k = a[i] + b[i];
    itb = d[1][k].begin();
    ite = d[1][k].end();
    ite--;
    if ((a[i] == *itb or a[i] == *ite) and d[1][k].size() != 1) t[i]++;
    if ((a[i] != *itb and a[i] != *ite) and d[1][k].size() != 1) t[i] += 2;
    ans[t[i]]++;
  }
  for (int i = 0; i < 9; i++) cout << ans[i] << " ";
  return 0;
}
