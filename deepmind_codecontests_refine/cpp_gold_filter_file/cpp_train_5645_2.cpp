#include <bits/stdc++.h>
using namespace std;
int q, l, r, L;
char s[200010];
int sum[200010][50];
int main() {
  cin >> (s + 1);
  L = strlen(s + 1);
  for (int i = 1; i <= L; ++i) s[i] -= 'a';
  for (int i = 1; i <= L; ++i) {
    for (int j = 0; j < 26; ++j) sum[i][j] = sum[i - 1][j];
    sum[i][s[i]]++;
  }
  scanf("%d", &q);
  while (q--) {
    vector<int> c;
    scanf("%d%d", &l, &r);
    if (l == r) {
      puts("Yes");
      continue;
    }
    if (s[l] != s[r]) {
      puts("Yes");
      continue;
    }
    int tot = 0;
    for (int i = 0; i < 26; ++i) {
      tot += ((sum[r][i] - sum[l - 1][i]) > 0 ? 1 : 0);
      if (sum[r][i] - sum[l - 1][i] == 0) continue;
      c.push_back(sum[r][i] - sum[l - 1][i]);
    }
    if (tot > 2)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
