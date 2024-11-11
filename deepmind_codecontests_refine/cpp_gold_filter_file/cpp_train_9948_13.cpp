#include <bits/stdc++.h>
using namespace std;
const int dd = (int)1e6 + 7;
int G[dd], T[dd], a[dd], b[dd];
int n, e;
int main() {
  scanf("%d %d", &n, &e);
  for (int i = 0; i < e; i++) {
    scanf("%d %d", &a[i], &b[i]);
    a[i]--, b[i]--;
  }
  int maxT = 0;
  srand(1488);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    vector<int> T;
    for (int j = 0; j < t; j++) {
      int x;
      scanf("%d", &x);
      maxT = max(maxT, x);
      x--;
      T.push_back(x);
    }
    G[i] = T[rand() % (int)T.size()];
    cout << G[i] + 1 << " ";
  }
  cout << "\n";
  while (1) {
    for (int i = 0; i < maxT; i++) T[i] = rand() % 2;
    int c = 0;
    for (int i = 0; i < e; i++) c += (T[G[a[i]]] != T[G[b[i]]]);
    if (c >= (e + 1) / 2) break;
  }
  for (int i = 0; i < maxT; i++) cout << T[i] + 1 << " ";
  return 0;
}
