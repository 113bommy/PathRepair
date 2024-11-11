#include <bits/stdc++.h>
using namespace std;
int n, m, q, w;
vector<int> fr[111111];
vector<int> ba[111111];
int num[1111111];
long long co[111111][222];
long long a[111111];
long long sum[111111];
long long pl[222];
long long ex[222];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= m; i++) {
    int how;
    scanf("%d", &how);
    if (how >= 500) num[i] = ++w;
    while (how--) {
      int temp;
      scanf("%d", &temp);
      sum[i] += a[temp];
      fr[i].push_back(temp);
      if (num[i]) ba[temp].push_back(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < ba[i].size(); j++) {
      for (int k = 0; k < ba[i].size(); k++) {
        co[ba[i][j]][num[ba[i][k]]]++;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!num[i]) {
      for (int j = 0; j < fr[i].size(); j++) {
        for (int k = 0; k < ba[fr[i][j]].size(); k++) {
          co[i][num[ba[fr[i][j]][k]]]++;
        }
      }
    }
  }
  while (q--) {
    char temp;
    scanf(" %c", &temp);
    if (temp == '+') {
      int k;
      long long x;
      scanf("%d%lld", &k, &x);
      if (!num[k]) {
        for (int i = 0; i < fr[k].size(); i++) a[fr[k][i]] += x;
      } else
        pl[num[k]] += x;
      for (int i = 1; i <= w; i++) ex[i] += x * co[k][i];
    } else {
      int k;
      scanf("%d", &k);
      long long dap = 0;
      if (!num[k]) {
        for (int i = 0; i < fr[k].size(); i++) dap += a[fr[k][i]];
        for (int i = 1; i <= w; i++) dap += co[k][i] * pl[i];
      } else
        dap = sum[k] + ex[num[k]];
      printf("%lld\n", dap);
    }
  }
}
