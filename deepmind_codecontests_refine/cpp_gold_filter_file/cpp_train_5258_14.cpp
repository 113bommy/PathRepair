#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, same, dif;
char s[100005], s1[100005], ans[100005];
vector<int> a, b;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", s, s1);
  for (i = 0; i < n; i++) {
    if (s[i] == s1[i]) {
      same++;
      if (s[i] == 'a')
        ans[i] = 'b';
      else
        ans[i] = 'a';
      a.push_back(i);
    } else {
      char temp = 'a';
      if (s[i] == temp || s1[i] == temp) temp++;
      if (s[i] == temp || s1[i] == temp) temp++;
      ans[i] = temp;
      dif++;
      b.push_back(i);
    }
  }
  int itr = a.size() - 1;
  int itr1 = b.size() - 1;
  int now = n;
  while (now > m) {
    if (same) {
      ans[a[itr]] = s[a[itr]];
      itr--;
      same--;
      now--;
      continue;
    }
    if (dif <= 1) {
      return 0 * printf("-1\n");
    }
    ans[b[itr1]] = s[b[itr1]];
    itr1--;
    ans[b[itr1]] = s1[b[itr1]];
    itr1--;
    dif -= 2;
    now--;
  }
  printf("%s\n", ans);
}
