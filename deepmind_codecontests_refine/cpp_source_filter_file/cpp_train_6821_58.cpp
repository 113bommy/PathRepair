#include <bits/stdc++.h>
using namespace std;
int a[5100][5100];
pair<int, int> vc[5001], vr[5001];
int main() {
  int n, m, k;
  scanf(" %d %d %d", &n, &m, &k);
  int x, y, z;
  pair<int, int> p;
  p.first = 0, p.second = -1;
  for (int i = 0; i < n; i++) vr[i] = p;
  for (int i = 0; i < m; i++) vc[i] = p;
  for (int i = 0; i < k; i++) {
    scanf(" %d %d %d", &x, &y, &z);
    if (x == 1) {
      vr[y - 1].first = z;
      vr[y - 1].second = i;
    } else {
      vc[y - 1].first = z;
      vc[y - 1].second = i;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vr[i].second != -1 && vc[j].second != -1) {
        if (vr[i].second > vc[i].second) {
          if (j != 0)
            printf(" %d", vr[i].first);
          else
            printf("%d", vr[i].first);
        } else {
          if (j != 0)
            printf(" %d", vc[j].first);
          else
            printf("%d", vc[j].first);
        }
      } else if (vr[i].second != -1) {
        if (j != 0)
          printf(" %d", vr[i].first);
        else
          printf("%d", vr[i].first);
      } else if (vc[j].second != -1) {
        if (j != 0)
          printf(" %d", vc[j].first);
        else
          printf("%d", vc[j].first);
      } else {
        if (j != 0)
          printf(" 0");
        else
          printf("0");
      }
    }
    printf("\n");
  }
  return 0;
}
