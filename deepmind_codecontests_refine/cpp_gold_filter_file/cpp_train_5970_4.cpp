#include <bits/stdc++.h>
using namespace std;
int n, k;
int f[4005][2005];
char str[2005][505];
int lcp[2005];
int arr[2005];
bool cmpStr(int i, int j) { return strcmp(str[i], str[j]) < 0; }
int work(int l, int r) {
  if (l >= r) return 0;
  static int stamp = 0;
  int id = stamp++;
  int p = l;
  for (int i = l + 1; i < r; i++)
    if (lcp[i] < lcp[p]) p = i;
  int idl = work(l, p);
  int idr = work(p + 1, r);
  for (int i = 0; i <= p - l + 1; i++)
    for (int j = 0; j <= r - p; j++)
      if (i + j <= k)
        f[id][i + j] =
            max(f[id][i + j], f[idl][i] + f[idr][j] + i * j * lcp[p]);
  return id;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
    arr[i] = i;
  }
  sort(arr, arr + n, cmpStr);
  for (int i = 0; i < n - 1; i++) {
    int lim = min(strlen(str[arr[i]]), strlen(str[arr[i + 1]]));
    lcp[i] = 0;
    while (lcp[i] < lim && str[arr[i]][lcp[i]] == str[arr[i + 1]][lcp[i]])
      lcp[i]++;
  }
  work(0, n - 1);
  printf("%d\n", f[0][k]);
}
