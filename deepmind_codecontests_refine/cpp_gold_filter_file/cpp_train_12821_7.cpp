#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
int n;
int arr[1010], brr[1010], trr[1010];
int cura[1010], curb[1010];
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    arr[i]--;
    trr[arr[i]] = i;
    cura[i] = i;
  }
  for (i = 0; i < n; i++) arr[i] = trr[i];
  for (i = 0; i < n; i++) {
    scanf("%d", &brr[i]);
    brr[i]--;
    trr[brr[i]] = i;
    curb[i] = i;
  }
  for (i = 0; i < n; i++) brr[i] = trr[i];
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  for (i = 0; i < n; i++) {
    if (arr[i] == cura[i] && brr[i] == curb[i]) continue;
    int p, q;
    for (j = i; j < n; j++)
      if (cura[j] == arr[i]) break;
    p = j;
    for (j = i; j < n; j++)
      if (curb[j] == brr[i]) break;
    q = j;
    ans.push_back(pair<pair<int, int>, pair<int, int> >(pair<int, int>(p, i),
                                                        pair<int, int>(i, q)));
    swap(cura[p], cura[i]);
    swap(curb[q], curb[i]);
  }
  printf("%d\n", ans.size());
  for (pair<pair<int, int>, pair<int, int> > &v : ans) {
    printf("%d %d %d %d\n", v.first.first + 1, v.first.second + 1,
           v.second.first + 1, v.second.second + 1);
  }
  return 0;
}
