#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m, val, t = 0, cnt, test;
  cin >> m;
  map<string, int> mp;
  string a, b, arr[2 * m + 5];
  vector<int> vec[2 * m + 5];
  for (i = 0, cnt = 0; i < m; i++) {
    cin >> a >> b;
    if (!mp[a]) mp[a] = ++cnt, arr[cnt] = a;
    if (!mp[b]) mp[b] = ++cnt, arr[cnt] = b;
    vec[mp[a]].push_back(mp[b]);
    vec[mp[b]].push_back(mp[a]);
  }
  n = cnt;
  printf("%d\n", n);
  for (i = 1; i <= n; i++) {
    sort(vec[i].begin(), vec[i].end());
    int pre = 1;
    for (j = 1, cnt = 0; j <= n; j++) {
      if (i != j and binary_search(vec[i].begin(), vec[i].end(), j) == false) {
        int tem = 0;
        for (k = 0; k < vec[j].size(); k++) {
          if (binary_search(vec[i].begin(), vec[i].end(), vec[j][k])) tem++;
        }
        if (tem > pre)
          pre = tem, cnt = 1;
        else if (tem == pre)
          cnt++;
      }
    }
    cout << arr[i] << ' ' << cnt << endl;
  }
  return 0;
}
