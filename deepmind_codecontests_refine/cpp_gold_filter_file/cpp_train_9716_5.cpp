#include <bits/stdc++.h>
using namespace std;
int n, m, t, mc[100001], nmc[100001], can[100001], p[100001];
int main() {
  cin >> n >> m;
  int anmc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    if (p[i] > 0) {
      mc[p[i]]++;
    } else {
      nmc[-p[i]]++;
      anmc++;
    }
  }
  int k = 0;
  for (int i = 1; i <= n; i++)
    if (mc[i] + (anmc - nmc[i]) == m) {
      can[i] = 1;
      k++;
    }
  for (int i = 1; i <= n; i++)
    if (p[i] > 0) {
      if (can[p[i]] && k == 1)
        cout << "Truth" << endl;
      else if (!can[p[i]])
        cout << "Lie" << endl;
      else
        cout << "Not defined" << endl;
    } else {
      if (!can[-p[i]])
        cout << "Truth" << endl;
      else if (can[-p[i]] && k == 1)
        cout << "Lie" << endl;
      else
        cout << "Not defined" << endl;
    }
  return 0;
}
