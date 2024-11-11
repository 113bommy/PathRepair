#include <bits/stdc++.h>
using namespace std;
const int MAXT = (1 << 18) + 5;
int icT[MAXT], dcT[MAXT];
const int MAXN = 100010;
int a[MAXN], idxofa[MAXN], b[MAXN];
int n;
priority_queue<pair<int, int> > dc, ic;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (int)(n); i++) {
    scanf("%d", &a[i]);
    idxofa[a[i]] = i;
  }
  for (int i = 0; i < (int)(MAXT); i++) icT[i] = dcT[i] = 1000000000;
  int NN = (1 << 18) - 1;
  for (int i = 1; i <= (int)(n); i++) {
    scanf("%d", &b[i]);
    if (i > idxofa[b[i]]) {
      dc.push(make_pair(-(i - idxofa[b[i]]), b[i]));
      dcT[NN + b[i]] = abs(i - idxofa[b[i]]);
      for (int node = (NN + b[i]) / 2; node; node >>= 1)
        dcT[node] = min(dcT[2 * node], dcT[2 * node + 1]);
    } else {
      ic.push(make_pair(-(i - 1), b[i]));
      icT[NN + b[i]] = abs(i - idxofa[b[i]]);
      for (int node = (NN + b[i]) / 2; node; node >>= 1)
        icT[node] = min(icT[2 * node], icT[2 * node + 1]);
    }
  }
  for (int t = 0; t < n; t++) {
    int dcres = dcT[1] - t;
    int icres = icT[1] + t;
    printf("%d\n", min(dcres, icres));
    while (dc.size() > 0 && -dc.top().first == t) {
      pair<int, int> qt = dc.top();
      dc.pop();
      ic.push(make_pair(-t - (idxofa[qt.second] - 1), qt.second));
      dcT[NN + qt.second] = 1000000000;
      icT[NN + qt.second] = -t;
      for (int node = (NN + qt.second) / 2; node; node >>= 1)
        icT[node] = min(icT[2 * node], icT[2 * node + 1]);
      for (int node = (NN + qt.second) / 2; node; node >>= 1)
        dcT[node] = min(dcT[2 * node], dcT[2 * node + 1]);
    }
    while (ic.size() > 0 && -ic.top().first == t) {
      pair<int, int> qt = ic.top();
      ic.pop();
      dc.push(make_pair(-t - (n - idxofa[qt.second]) - 1, qt.second));
      icT[NN + qt.second] = 1000000000;
      dcT[NN + qt.second] = t + 1 + n - idxofa[qt.second];
      for (int node = (NN + qt.second) / 2; node; node >>= 1)
        icT[node] = min(icT[2 * node], icT[2 * node + 1]);
      for (int node = (NN + qt.second) / 2; node; node >>= 1)
        dcT[node] = min(dcT[2 * node], dcT[2 * node + 1]);
    }
  }
  return 0;
}
