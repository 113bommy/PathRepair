#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, k;
int a[MAXN];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  map<int, int> dict;
  set<int> one;
  for (int i = 0; i < k; i++) {
    {
      dict[a[i]]++;
      if (dict[a[i]] == 1)
        one.insert(a[i]);
      else if (dict[a[i]] == 2)
        one.erase(a[i]);
    };
  }
  for (int l = 0, r = k;; l++, r++) {
    if (one.size() == 0)
      puts("Nothing");
    else
      printf("%d\n", *one.rbegin());
    if (r == n) break;
    {
      dict[a[r]]++;
      if (dict[a[r]] == 1)
        one.insert(a[r]);
      else if (dict[a[r]] == 2)
        one.erase(a[r]);
    };
    {
      dict[a[l]]--;
      if (dict[a[l]] == 1)
        one.insert(a[l]);
      else if (dict[a[l]] == 0) {
        one.erase(a[l]);
        dict.erase(a[l]);
      }
    };
  }
  return 0;
}
