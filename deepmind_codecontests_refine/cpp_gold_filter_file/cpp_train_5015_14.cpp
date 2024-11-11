#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;
int main() {
  int q;
  scanf("%i", &q);
  while (q--) {
    int n, k;
    scanf("%d%d", &n, &k);
    const string w[] = {"RGB", "GBR", "BRG"};
    string s;
    cin >> s;
    int i = 0;
    int res = k;
    vector<int> pos[3];
    for (const char &c : s) {
      for (int j = 0; j < 3; ++j) {
        if (c == w[j][i % 3]) {
          pos[j].push_back(i);
          int start = i - k + 1;
          int safe = pos[j].size() -
                     (lower_bound(pos[j].begin(), pos[j].end(), start) -
                      pos[j].begin());
          int cres = k - safe;
          res = min(res, cres);
        }
      }
      ++i;
    }
    printf("%d\n", res);
  }
}
