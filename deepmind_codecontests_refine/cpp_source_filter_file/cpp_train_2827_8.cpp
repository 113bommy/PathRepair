#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int vis[N], cnt[N], n, maxx, L, R;
vector<int> table;
int main() {
  scanf("%d", &(n));
  for (int i = (1); i <= (n); i++) {
    int x;
    scanf("%d", &(x));
    if (!vis[x]) vis[x] = 1, table.push_back(x);
    cnt[x]++;
  }
  sort(table.begin(), table.end());
  maxx = L = R = 0;
  for (int i = (0); i <= (table.size() - 1); i++) {
    int j = i + 1, sum = cnt[table[i]];
    while (table[j] - table[j - 1] == 1 && cnt[table[j]] > 1)
      sum += cnt[table[j++]];
    int cur = j - 1;
    if (table[j] - table[j - 1] == 1 && cnt[table[j]] == 1) cur++, sum++;
    if (sum > maxx) maxx = sum, L = table[i], R = table[j];
    i = j - 1;
  }
  cout << maxx << endl;
  if (cnt[L] != maxx) {
    while (cnt[L]--) printf("%d ", L);
    for (int i = (L + 1); i <= (R - 1); i++)
      while (cnt[i] >= 1) printf("%d ", i), cnt[i]--;
    while (cnt[R]--) printf("%d ", R);
    for (int i = (R - 1); i >= (L + 1); --i)
      if (i != L + 1)
        printf("%d ", i);
      else
        printf("%d", i);
  } else
    while (cnt[L]--)
      if (cnt[L])
        printf("%d ", L);
      else
        printf("%d", L);
  return 0;
}
