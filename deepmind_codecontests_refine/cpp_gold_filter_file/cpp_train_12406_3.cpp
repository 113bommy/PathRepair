#include <bits/stdc++.h>
using namespace std;
const int maxn = 10003;
typedef struct {
  int val;
  int id;
} pt;
int n, k, cur, mcost = 1 << 30;
string s, str, ans;
pt mat[maxn];
bool comp(const pt &a, const pt &b) {
  if (a.val != b.val) return a.val < b.val;
  if (s[a.id] == s[b.id]) {
    if (s[a.id] >= cur + '0')
      return a.id < b.id;
    else
      return a.id > b.id;
  }
  return s[a.id] > s[b.id];
}
int main() {
  scanf("%d%d\n", &n, &k);
  cin >> s;
  int sz = s.size();
  for (; cur < 10; cur++) {
    str = s;
    for (int i = 0; i < sz; i++) {
      mat[i].id = i;
      mat[i].val = abs(s[i] - '0' - cur);
    }
    sort(mat, mat + n, comp);
    int cost = 0;
    for (int i = 0; i < k; i++) {
      cost += mat[i].val;
      str[mat[i].id] = cur + '0';
    }
    if (mcost > cost) {
      mcost = cost;
      ans = str;
    } else if (mcost == cost && ans > str)
      ans = str;
  }
  cout << mcost << '\n';
  cout << ans << '\n';
}
