#include <bits/stdc++.h>
using namespace std;
char s1[2103], s2[2103];
char arr[4109];
int z[4509], sz;
void ZAlgo() {
  int l = 0, r = 0;
  for (int i = 1; i < sz; ++i) {
    if (i > r) {
      l = r = i;
      while (r < sz && arr[r - l] == arr[r]) ++r;
      z[i] = r - l;
      --r;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1)
        z[i] = z[k];
      else {
        l = i;
        while (r < sz && arr[r - l] == arr[r]) ++r;
        z[i] = r - l;
        --r;
      }
    }
  }
}
pair<int, int> ans[2103];
int main() {
  int ansSz = 0;
  scanf("%s", s1);
  scanf("%s", s2);
  int n = strlen(s1), m = strlen(s2);
  int cur = 0;
  while (cur < m) {
    sz = 0;
    for (int i = cur; i < m; ++i) arr[sz++] = s2[i];
    arr[sz++] = '?';
    for (int i = 0; i < n; ++i) arr[sz++] = s1[i];
    ZAlgo();
    int mx = 0, ind = -1;
    for (int i = m - cur + 1; i < sz; ++i)
      if (z[i] > mx) mx = z[i], ind = i - m + cur - 1;
    if (ind == -1) {
      puts("-1");
      return 0;
    }
    reverse(arr + m - cur + 1, arr + sz);
    ZAlgo();
    bool rev = 0;
    for (int i = m - cur + 1, j = n - 1; i < sz; ++i, --j)
      if (z[i] > mx) mx = z[i], ind = j, rev = 1;
    ans[ansSz++] =
        rev ? make_pair(ind, ind - mx + 1) : make_pair(ind, ind + mx - 1);
    cur += mx;
  }
  printf("%d\n", ansSz);
  for (int i = 0; i < ansSz; ++i)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  return 0;
}
