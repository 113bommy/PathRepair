#include <bits/stdc++.h>
using namespace std;
const int maxn = 40400;
int N, n, T, x, y, k, t;
int c[maxn], cnt[maxn];
int ID[maxn], I[maxn], J[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d%d", &n, &t);
  cnt[(((0 + 100) * 200) + ((0) + 100))] = n;
  for (int i = -65; i < 66; i++)
    for (int j = -65; j < 66; j++) {
      ID[N] = (((i + 100) * 200) + ((j) + 100));
      I[N] = i;
      J[N++] = j;
    }
  while (1) {
    k = 0;
    for (int i = 0; i < N; T++, i++)
      if (cnt[ID[i]] > 3) {
        cnt[ID[i]] -= 4;
        c[ID[i] + 200]++;
        cnt[ID[i] - 200]++;
        c[ID[i] + 1]++;
        cnt[ID[i] - 1]++;
        k = 1;
      }
    if (k == 0) break;
    for (int i = 0; i < N; i++)
      if (c[ID[i]]) {
        cnt[ID[i]] += c[ID[i]];
        c[ID[i]] = 0;
      }
  }
  while (t--) {
    scanf("%d%d", &x, &y);
    if (x < -90 or x > 90 or y < -90 or y > 90)
      printf("0\n");
    else
      printf("%d\n", cnt[(((x + 100) * 200) + ((y) + 100))]);
  }
  return 0;
}
