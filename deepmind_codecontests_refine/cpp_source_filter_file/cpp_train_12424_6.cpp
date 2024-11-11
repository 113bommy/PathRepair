#include <bits/stdc++.h>
const double eps = 1e-10;
using namespace std;
using ul = unsigned long long;
using PII = pair<int, int>;
const int NN = 200111;
const int NZ = 1111;
const int MM = 151;
const int need = (1 << 30) - 1;
int n, m, s, t, a, b, k, c;
int r;
int col[NN];
vector<int> gr[NN];
int push(int x) {
  set<pair<int, int>> st;
  int d[NN];
  for (int i = 0; i < NN; i++) {
    d[i] = 1000000000;
  }
  int res = -1;
  d[s] = 0;
  st.insert({d[s], s});
  while (!st.empty()) {
    PII a = *st.begin();
    int wona = a.first;
    int wvero = a.second;
    st.erase(st.begin());
    if (wona == x) continue;
    int to;
    for (int y = 0; y < gr[wvero].size(); y++) {
      to = gr[wvero][y];
      if (d[to] > wona + 1) {
        int ff;
        if (to == t) return 1;
        st.erase({d[to], to});
        if (col[to]) {
          ff = 0;
        } else {
          ff = wona + 1;
        }
        d[to] = ff;
        st.insert({ff, to});
        res = max(res, ff);
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int a;
    scanf("%d", &a);
    col[a] = 1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  scanf("%d %d", &s, &t);
  int low = 0, high = n;
  int md = -1;
  bool flag = 0;
  while (low < high) {
    md = (low + high) >> 1;
    if (push(md)) {
      high = md;
    } else {
      low = md + 1;
    }
  }
  if (!push(low)) {
    printf("d\n", -1);
    return 0;
  }
  printf("%d\n", low);
  return 0;
  system("pause");
}
