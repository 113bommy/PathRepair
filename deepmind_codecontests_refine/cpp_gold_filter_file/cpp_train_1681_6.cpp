#include <bits/stdc++.h>
using namespace std;
vector<int> row[1001];
vector<int> conlum[1001];
int a[1001][1001];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      row[i].push_back(a[i][j]);
      conlum[j].push_back(a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(row[i].begin(), row[i].end());
    row[i].erase(unique(row[i].begin(), row[i].end()), row[i].end());
  }
  for (int j = 0; j < m; j++) {
    sort(conlum[j].begin(), conlum[j].end());
    conlum[j].erase(unique(conlum[j].begin(), conlum[j].end()),
                    conlum[j].end());
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int max1, max2, order1, order2;
      max1 = row[i].size();
      max2 = conlum[j].size();
      order1 = lower_bound(row[i].begin(), row[i].end(), a[i][j]) -
               row[i].begin() + 1;
      order2 = lower_bound(conlum[j].begin(), conlum[j].end(), a[i][j]) -
               conlum[j].begin() + 1;
      if (order1 < order2) {
        int d = abs(order1 - order2);
        max1 += d;
      } else {
        int d = abs(order1 - order2);
        max2 += d;
      }
      printf("%d ", max(max1, max2));
    }
    printf("\n");
  }
  return 0;
}
