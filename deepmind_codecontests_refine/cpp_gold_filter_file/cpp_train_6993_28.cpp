#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int si[N + 5], arr[N + 5];
int n, q;
int last[N + 5];
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    si[arr[i]]++;
    last[arr[i]] = i + 1;
  }
  int ans = 0;
  int i = 0;
  while (i < n) {
    int now = arr[i];
    int tot = 0, mex = si[now];
    int fin = last[arr[i]];
    while (i < fin) {
      tot++;
      fin = max(fin, last[arr[i]]);
      mex = max(mex, si[arr[i]]);
      i++;
    }
    ans += tot - mex;
  }
  printf("%d\n", ans);
}
