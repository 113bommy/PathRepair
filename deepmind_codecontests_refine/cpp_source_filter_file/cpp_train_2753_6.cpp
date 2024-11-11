#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int> > > ans(int n) {
  if (n == 1) {
    vector<int> v;
    v.push_back(1);
    vector<vector<int> > w;
    w.push_back(v);
    vector<vector<vector<int> > > h;
    h.push_back(w);
    return h;
  }
  vector<vector<vector<int> > > old = ans(n - 1);
  vector<vector<vector<int> > > nw;
  bool beg = true;
  for (int i = 0; i < (int)(int)(old).size(); ++i) {
    if (beg)
      for (int j = 0; j < (int)(int)(old[i]).size() + 1; ++j) {
        vector<vector<int> > w;
        for (int t = 0; t < (int)(int)(old[i]).size(); ++t) {
          w.push_back(old[i][t]);
          if (t == j) w[(int)(w).size() - 1].push_back(n);
        }
        if (j == (int)(old[i]).size()) {
          vector<int> q;
          q.push_back(n);
          w.push_back(q);
        }
        nw.push_back(w);
      }
    else
      for (int j = (int)(int)(old[i]).size(); j >= 0; --j) {
        vector<vector<int> > w;
        for (int t = 0; t < (int)(int)(old[i]).size(); ++t) {
          w.push_back(old[i][t]);
          if (t == j) w[(int)(w).size() - 1].push_back(n);
        }
        if (j == (int)(old[i]).size()) {
          vector<int> q;
          q.push_back(n);
          w.push_back(q);
        }
        nw.push_back(w);
      }
    beg != beg;
  }
  return nw;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<vector<int> > > x = ans(n);
  printf("%d\n", (int)(x).size());
  for (int i = 0; i < (int)(int)(x).size(); ++i) {
    for (int j = 0; j < (int)(int)(x[i]).size(); ++j) {
      if (j > 0) printf(",");
      printf("{");
      for (int k = 0; k < (int)(int)(x[i][j]).size(); ++k) {
        if (k > 0) printf(",");
        printf("%d", x[i][j][k]);
      }
      printf("}");
    }
    printf("\n");
  }
  return 0;
}
