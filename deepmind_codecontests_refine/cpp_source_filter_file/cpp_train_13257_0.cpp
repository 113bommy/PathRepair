#include <bits/stdc++.h>
using namespace std;
void Rd(int& res) {
  res = 0;
  char c;
  while (c = getchar(), c < 48)
    ;
  do res = res * 10 + (c & 15);
  while (c = getchar(), c > 47);
}
vector<int> num[5005], ans, id;
int n, k, a, x, y, m, tot;
int L[5005];
int main() {
  Rd(n);
  for (int i = 1; i <= n; i++) {
    Rd(k), Rd(a), Rd(x), Rd(y), Rd(m);
    tot += k;
    num[i].push_back(a);
    for (int j = 2; j <= k; j++) {
      a = (1LL * a * x + y) % m;
      num[i].push_back(a);
    }
  }
  ans.push_back(-1);
  id.push_back(-1);
  while (tot--) {
    int mi = 1e9 + 5, miid = -1;
    for (int i = 1; i <= n; i++) {
      if (L[i] < num[i].size() && num[i][L[i]] >= ans[ans.size() - 1] &&
          num[i][L[i]] < mi) {
        mi = num[i][L[i]];
        miid = i;
      }
    }
    if (~miid) {
      id.push_back(miid);
      ans.push_back(num[miid][L[miid]++]);
      continue;
    }
    mi = 1e9 + 5, miid = -1;
    for (int i = 1; i <= n; i++) {
      if (L[i] < num[i].size() && num[i][L[i]] < mi) {
        mi = num[i][L[i]];
        miid = i;
      }
    }
    id.push_back(miid);
    ans.push_back(num[miid][L[miid]++]);
  }
  int allc = 0;
  for (int i = 2; i < ans.size(); i++)
    if (ans[i] < ans[i - 1]) allc++;
  printf("%d\n", allc);
  if (ans.size() <= 200000) {
    for (int i = 1; i < ans.size(); i++) printf("%d %d\n", ans[i], id[i]);
  }
  return 0;
}
