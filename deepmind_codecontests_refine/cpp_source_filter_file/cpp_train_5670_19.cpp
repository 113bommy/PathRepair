#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)3e6 + 7;
const int INF = (int)1e9 + 9;
int n;
int b, first;
int cars;
int isFree[MAXN];
int add[MAXN];
int segL[MAXN];
int segR[MAXN];
int main() {
  scanf("%d%d%d", &n, &b, &first);
  scanf("%d", &cars);
  for (int i = 1; i <= cars; i++) {
    int query, len, id;
    scanf("%d", &query);
    if (query == 1) {
      scanf("%d", &len);
      int put = -1;
      for (int place = 0; place <= n - len; place++) {
        int l = place - b;
        int r = place + len + first - 1;
        int sum = isFree[r];
        if (l >= 0) sum -= isFree[l];
        if (!sum) {
          put = place;
          break;
        }
      }
      printf("%d\n", put);
      if (put >= 0) {
        segL[i] = put;
        segR[i] = put + len;
        for (int j = put; j <= put + len; j++) add[j]++;
      }
    } else {
      scanf("%d", &id);
      for (int j = segL[id]; j <= segR[id]; j++) add[j]--;
    }
    int pref = 0;
    for (int x = 0; x <= n; x++) {
      pref += add[x];
      add[x] = 0;
      isFree[x] += pref;
    }
  }
  return 0;
}
