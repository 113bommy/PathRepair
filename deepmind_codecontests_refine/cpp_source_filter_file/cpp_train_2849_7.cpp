#include <bits/stdc++.h>
using namespace std;
map<string, int> my;
map<string, int>::iterator it;
map<int, string> mine;
vector<int> v[11111];
map<int, int> cnt[11111];
int flag[11111];
int main() {
  int m;
  while (~scanf("%d", &m)) {
    int mm = m;
    my.clear();
    mine.clear();
    for (int i = 1; i <= m * 2; i++) cnt[i].clear();
    for (int i = 1; i <= m * 2; i++) v[i].clear();
    int n = 0;
    while (mm--) {
      string te1, te2;
      cin >> te1 >> te2;
      if (my[te1] == 0) my[te1] = ++n;
      if (my[te2] == 0) my[te2] = ++n;
      v[my[te1]].push_back(my[te2]);
      v[my[te2]].push_back(my[te1]);
    }
    for (it = my.begin(); it != my.end(); it++) {
      mine.insert(pair<int, string>(it->second, it->first));
    }
    for (int i = 1; i <= n; i++) {
      int l = v[i].size();
      if (l < 2) continue;
      for (int j = 0; j <= l - 2; j++) {
        int te = v[i][j];
        for (int k = j + 1; k <= l - 1; k++) {
          int te2 = v[i][k], ff = 0;
          int ll = v[te].size();
          for (int kk = 0; kk <= ll - 1; kk++) {
            if (v[te][kk] == te2) {
              ff = 1;
              break;
            }
          }
          if (ff == 1) continue;
          cnt[te][te2]++;
          cnt[te2][te]++;
        }
      }
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
      int tt = 0, maxx = 1;
      for (map<int, int>::iterator curr = cnt[i].begin(); curr != cnt[i].end();
           ++curr)
        if (curr->second > maxx) {
          maxx = curr->second;
          tt = 1;
        } else if (curr->second == maxx) {
          tt++;
        }
      cout << mine[i] << " ";
      if (tt == 1) {
        printf("%d\n", n - 1 - v[i].size());
      } else
        printf("%d\n", tt);
    }
  }
  return 0;
}
