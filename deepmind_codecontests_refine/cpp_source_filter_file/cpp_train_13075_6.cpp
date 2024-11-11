#include <bits/stdc++.h>
using namespace std;
char s[1234], t[1234];
int n, m;
vector<int> tvec, pr;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  scanf("%s", t);
  pr.clear();
  int ans = n + 1;
  for (int i = 0; i < m; i++) {
    int tmp = n;
    tvec.clear();
    for (int j = 0; j < n; j++) {
      if (t[i + j] == s[j])
        tmp--;
      else
        tvec.push_back(j + 1);
    }
    if (tmp < ans) {
      ans = tmp;
      pr.clear();
      for (int k = 0; k < tvec.size(); k++) pr.push_back(tvec[k]);
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < pr.size(); i++) printf("%d ", pr[i]);
  printf("\n");
  return 0;
}
