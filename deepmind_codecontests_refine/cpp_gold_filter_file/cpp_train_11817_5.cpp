#include <bits/stdc++.h>
using namespace std;
int v[4005] = {0}, d[4005] = {0}, id[4005] = {0};
long long p[4005] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> d[i] >> p[i];
    id[i] = i + 1;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t, j;
    for (t = i + 1, j = v[i]; j > 0 && t < n; j--, t++) p[t] -= j;
    for (t = i + 1; t < n; t++)
      if (p[t] < 0) {
        for (j = t + 1; j < n; j++) p[j] -= d[t];
      }
    for (t = j = i + 1; j < n; j++)
      if (p[j] >= 0) {
        v[t] = v[j];
        d[t] = d[j];
        p[t] = p[j];
        id[t] = id[j];
        t++;
      }
    n = t;
  }
  cout << n << endl;
  for (int i = 0; i < n; i++) cout << id[i] << ' ';
  cout << endl;
  return 0;
}
