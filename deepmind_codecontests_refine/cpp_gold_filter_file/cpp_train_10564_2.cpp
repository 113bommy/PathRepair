#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int v[N];
bool ans[N];
bool used[N];
int main() {
  int casnum, n, m;
  cin >> casnum;
  while (casnum--) {
    memset(used, 1, sizeof(used));
    memset(ans, 0, sizeof(ans));
    scanf("%d%d", &n, &m);
    for (int i = (1); i <= (m); ++i) scanf("%d", &v[i]);
    vector<pair<int, int> > vec;
    for (int i = 0; i < (n - 1); ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      vec.push_back(pair<int, int>(x, y));
    }
    bool flag = 0;
    int tmp = 0;
    for (int i = 0; i < (n - 1); ++i) {
      if (vec[i].second == 1 && flag == 0) {
        flag = 1;
        for (int k = (vec.size() - 1); k >= (i); --k) used[vec[k].first] = 0;
        int value = 1e9;
        for (int k = (1); k <= (m); ++k) {
          if (v[k] <= tmp && used[k]) {
            ans[k] = 1;
            value = min(value, v[k]);
          }
        }
        tmp -= value;
      }
      if (vec[i].first == 0)
        tmp++;
      else
        --v[vec[i].first];
    }
    for (int i = (1); i <= (m); ++i) {
      if (tmp >= v[i] || ans[i])
        putchar('Y');
      else
        putchar('N');
    }
    puts("");
  }
  return 0;
}
