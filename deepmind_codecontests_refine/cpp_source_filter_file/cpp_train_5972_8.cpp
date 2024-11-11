#include <bits/stdc++.h>
using namespace std;
const int V = 1000;
int a[V][V];
bool changeC[V], changeR[V];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; ++i) changeR[i] = false;
  for (int i = 0; i < m; ++i) changeC[i] = false;
  while (1) {
    bool over = true;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < m; ++j)
        sum += (changeR[i] ^ changeC[j]) ? -a[i][j] : a[i][j];
      if (sum < 0) {
        changeR[i] ^= 1;
        over = false;
      }
    }
    for (int i = 0; i < m; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j)
        sum += (changeR[j] ^ changeC[i]) ? -a[j][i] : a[j][i];
      if (sum < 0) {
        changeC[i] ^= 1;
        over = false;
      }
    }
    if (!over) break;
  }
  vector<int> ansr, ansc;
  for (int i = 0; i < n; ++i) {
    if (changeR[i]) ansr.push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    if (changeC[i]) ansc.push_back(i);
  }
  cout << ansr.size();
  for (int i = 0; i < ansr.size(); ++i) printf(" %d", ansr[i] + 1);
  puts("");
  cout << ansc.size();
  for (int i = 0; i < ansc.size(); ++i) printf(" %d", ansc[i] + 1);
  puts("");
}
