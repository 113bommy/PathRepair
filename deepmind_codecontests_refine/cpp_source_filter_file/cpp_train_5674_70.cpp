#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int v[101];
  int t = 0;
  int vo[101];
  for (int i = 0; i < 101; i++) vo[i] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 101; j++) v[j] = 0;
    for (int j = 1; j <= n; j++) {
      cin >> t;
      v[j] = t;
    }
    int maxc = 0, maxv = 0;
    for (int j = 1; j <= n; j++)
      if (v[j] > maxv) {
        maxc = j;
        maxv = v[j];
      }
    vo[maxc]++;
  }
  int maxc = 0, maxv = 0;
  for (int i = 0; i < n; i++)
    if (vo[i] > maxv) {
      maxc = i;
      maxv = vo[i];
    }
  cout << maxc << endl;
}
