#include <bits/stdc++.h>
using namespace std;
int arr[101][51];
int main() {
  int n, m, k, w, x, tmpnum;
  cin >> n >> m >> k >> w;
  string s, tmp, tmp1;
  string s2[m];
  map<string, int> Map;
  for (int i = 0; i < m; i++) {
    cin >> s2[i];
    Map[s2[i]] = i;
  }
  map<string, map<int, int> > Map2;
  map<string, map<int, int> >::iterator it;
  map<int, int>::iterator IT;
  for (int i = 0; i < k; i++) {
    cin >> s;
    s.erase(s.size() - 1);
    do {
      cin >> tmp >> tmpnum;
      Map2[s][Map[tmp]] = tmpnum;
    } while (getchar() == ',');
  }
  vector<map<string, int> > ans;
  map<string, int>::iterator it2;
  ans.resize(n);
  for (int i = 0; i < w; i++) {
    cin >> x >> s;
    arr[x - 1][Map[s]]++;
    for (it = Map2.begin(); it != Map2.end(); it++) {
      int cur = 1E9;
      for (IT = it->second.begin(); IT != it->second.end(); IT++) {
        cur = min(cur, arr[x - 1][IT->first] / IT->second);
      }
      ans[x - 1][it->first] += cur;
      for (IT = it->second.begin(); IT != it->second.end(); IT++) {
        arr[x - 1][IT->first] -= IT->second * cur;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 51; j++) {
      if (arr[i][j]) {
        tmp1 = s2[j];
        ans[i][tmp1] = arr[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i].size() << endl;
    for (it2 = ans[i].begin(); it2 != ans[i].end(); it2++) {
      if (it2->second) cout << it2->first << " " << it2->second << endl;
    }
  }
  return 0;
}
