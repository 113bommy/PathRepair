#include <bits/stdc++.h>
using namespace std;
const int N = 300003;
int act[N];
int last[N];
int main() {
  memset(last, -1, sizeof last);
  int n, q, all = 0;
  int prev_T = 0;
  scanf("%d %d", &n, &q);
  vector<pair<int, int> > v;
  for (int j = 0; j < q; j++) {
    int type, x;
    scanf("%d %d", &type, &x);
    if (type == 1) {
      v.push_back({x, j});
      ++all;
      act[x]++;
    } else if (type == 2) {
      all -= act[x];
      act[x] = 0;
      last[x] = j;
    } else if (prev_T < x) {
      for (int i = prev_T; i < x; i++) {
        if (act[v[i].first] && last[v[i].first] < v[i].second) {
          --act[v[i].first];
          --all;
        }
      }
      prev_T = x;
    }
    printf("%d\n", all);
  }
}
