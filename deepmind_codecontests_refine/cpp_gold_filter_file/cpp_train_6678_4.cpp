#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long arr[maxn];
int jl[maxn];
int n;
struct newt {
  int l, r, id;
  newt() {}
  newt(int x, int y, int z) { l = x, r = y, id = z; }
} e[maxn];
int cnt = 0;
int main() {
  scanf("%d", &n);
  long long bj;
  int maxx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &arr[i]);
    jl[arr[i]]++;
    if (jl[arr[i]] >= maxx) {
      bj = arr[i], maxx = jl[arr[i]];
    }
  }
  int cs = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == bj) {
      int j;
      for (j = i - 1; j >= 1; j--) {
        if (arr[j] == bj) break;
        ++cnt;
        if (arr[j] > bj)
          e[cnt] = newt(j, j + 1, 2);
        else
          e[cnt] = newt(j, j + 1, 1);
        arr[j] = bj;
      }
      for (j = i + 1; j <= n; j++) {
        if (arr[j] == bj) break;
        ++cnt;
        if (arr[j] > bj)
          e[cnt] = newt(j, j - 1, 2);
        else
          e[cnt] = newt(j, j - 1, 1);
        arr[j] = bj;
      }
      i = j - 1;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++)
    cout << e[i].id << " " << e[i].l << " " << e[i].r << endl;
  return 0;
}
