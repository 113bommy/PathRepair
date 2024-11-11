#include <bits/stdc++.h>
using namespace std;
int chh;
const int N = 100005;
int n;
char s[N];
vector<int> q[30];
char ans[N];
int main() {
  int i, j, k, x, size, e;
  while (scanf("%s", s) != EOF) {
    n = strlen(s);
    for (i = 0; i < 26; i++) q[i].clear();
    for (i = 0; i < n; i++) q[s[i] - 'a'].push_back(i);
    x = -1, e = 0;
    for (i = 25; i >= 0; i--) {
      if (q[i].empty()) continue;
      j = upper_bound(q[i].begin(), q[i].end(), x) - q[i].begin();
      size = q[i].size();
      if (j == size + 1) continue;
      for (k = j; k < size; k++) ans[e++] = char('a' + i);
      x = q[i][size - 1];
    }
    ans[e] = 0;
    printf("%s\n", ans);
  }
  return 0;
}
