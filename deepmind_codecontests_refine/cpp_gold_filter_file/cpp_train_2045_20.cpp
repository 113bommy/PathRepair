#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 100010;
int n;
int a[maxn];
vector<pair<vector<int>, vector<int> > > ans;
void process(const vector<int>& v) {
  vector<int> res = v;
  int len = int((v).size());
  for (int iter = 0; iter < len; ++iter) {
    for (int i = 0; i < len; ++i) {
      int cur = a[res[i]];
      int ind = -1;
      for (int j = 0; j < int((res).size()); ++j) {
        if (res[j] == cur) {
          ind = j;
          break;
        }
      }
      if (ind >= 0) swap(a[cur], a[res[i]]), swap(res[ind], res[i]);
    }
  }
  ans.push_back(make_pair(v, res));
}
int u[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];
  vector<vector<int> > v2, v3;
  for (int i = 0; i < n; ++i) {
    if (!u[i]) {
      int cur = i;
      vector<int> cycle;
      while (!u[cur]) {
        u[cur] = 1;
        cycle.push_back(cur);
        cur = a[cur];
      }
      while (int((cycle).size()) > 3) {
        vector<int> poss;
        int cc = min(5, int((cycle).size()));
        for (int iter = 0; iter < cc; ++iter) {
          poss.push_back(cycle.back());
          if (iter < cc - 1) cycle.pop_back();
        }
        process(poss);
      }
      if (int((cycle).size()) == 2)
        v2.push_back(cycle);
      else if (int((cycle).size()) == 3)
        v3.push_back(cycle);
    }
  }
  while (int((v2).size()) || int((v3).size())) {
    if (int((v2).size()) && int((v3).size())) {
      vector<int> cur = v2.back();
      cur.insert(cur.end(), v3.back().begin(), v3.back().end());
      v2.pop_back();
      v3.pop_back();
      process(cur);
    } else {
      while (int((v2).size())) {
        int tt = min(2, int((v2).size()));
        vector<int> cur;
        for (int iter = 0; iter < tt; ++iter)
          cur.insert(cur.end(), v2.back().begin(), v2.back().end()),
              v2.pop_back();
        process(cur);
      }
      while (int((v3).size())) {
        int tt = min(3, int((v3).size()));
        vector<int> cur;
        for (int iter = 0; iter < tt; ++iter)
          cur.insert(cur.end(), v3.back().begin(), v3.back().end()),
              v3.pop_back();
        int c1 = min(5, int((cur).size()));
        int rem = int((cur).size()) - c1;
        process(vector<int>(cur.begin(), cur.begin() + c1));
        vector<int> tmp;
        for (int i = 0; i < int((cur).size()); ++i)
          if (a[cur[i]] != cur[i]) tmp.push_back(cur[i]);
        if (int((tmp).size())) process(tmp);
      }
    }
  }
  printf("%d\n", int((ans).size()));
  for (int i = 0; i < int((ans).size()); ++i) {
    printf("%d\n", int((ans[i].first).size()));
    for (int j = 0; j < int((ans[i].first).size()); ++j)
      printf("%d ", ans[i].first[j] + 1);
    printf("\n");
    for (int j = 0; j < int((ans[i].second).size()); ++j)
      printf("%d ", ans[i].second[j] + 1);
    printf("\n");
  }
  return 0;
}
