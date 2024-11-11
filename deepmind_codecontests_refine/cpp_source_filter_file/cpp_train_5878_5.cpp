#include <bits/stdc++.h>
using namespace std;
int v[500000];
int x[500000], last[500000], usedme[500000], cnt[500000];
map<int, int> m;
vector<int> ans;
set<int> s;
int main(void) {
  int n;
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (!m.count(v[i])) {
      m[v[i]] = i;
      x[i] = v[i];
    }
  }
  for (i = 0; i < n; i++) v[i] = m[v[i]];
  memset(last, -1, sizeof last);
  memset(usedme, -1, sizeof usedme);
  int lastused = -1;
  for (i = 0; i < n; i++) {
    cnt[v[i]]++;
    if (last[v[i]] == -1) {
      last[v[i]] = i;
      s.insert(v[i]);
    } else {
      if (cnt[v[i]] == 4) {
        ans.push_back(v[i]);
        ans.push_back(v[i]);
        ans.push_back(v[i]);
        ans.push_back(v[i]);
        for (j = lastused + 1; j <= i; j++) {
          usedme[v[j]] = -1;
          cnt[v[j]] = 0;
          last[v[j]] = -1;
        }
        lastused = i;
        s.clear();
      } else {
        if (usedme[v[i]] != -1) {
          ans.push_back(usedme[v[i]]);
          ans.push_back(v[i]);
          ans.push_back(usedme[v[i]]);
          ans.push_back(v[i]);
          for (j = lastused + 1; j <= i; j++) {
            usedme[v[j]] = -1;
            cnt[v[j]] = 0;
            last[v[j]] = -1;
          }
          lastused = i;
          s.clear();
        } else {
          set<int>::iterator it = s.upper_bound(last[v[i]]), tmp;
          while (it != s.end()) {
            usedme[*it] = v[i];
            tmp = it;
            it++;
            s.erase(tmp);
          }
          s.insert(v[i]);
          last[v[i]] = i;
        }
      }
    }
  }
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) {
    printf("%d ", x[ans[i]]);
  }
  printf("\n");
  return 0;
}
