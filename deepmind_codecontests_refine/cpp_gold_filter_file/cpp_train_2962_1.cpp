#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[511][511];
double w[511];
double esum[511];
int used[511];
double ansV = 0;
double ansE = 0;
int findMaxEV() {
  double mwe = 0;
  int ind = 0;
  for (int i = 1; i <= n; i++)
    if (used[i] == 0 && (esum[i] > 0 && w[i] / esum[i] > mwe)) {
      mwe = w[i] / esum[i];
      ind = i;
    }
  if (ansE > 0 && mwe < ansV / ansE) ind = 0;
  return ind;
}
void add(int ind) {
  used[ind] = 1;
  ansV += w[ind];
  ansE += esum[ind];
  for (int i = 1; i <= n; i++)
    if (a[ind][i] > 0 && used[i] == 0) esum[i] += a[ind][i];
}
int main() {
  cin >> n >> m;
  for (int j = 1; j <= n; j++) cin >> w[j];
  for (int j = 0; j < m; j++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x][y] = z;
    a[y][x] = z;
  }
  double megaAns = 0;
  for (int s = 1; s <= n; s++) {
    for (int i = 1; i <= n; i++) {
      used[i] = 0;
      esum[i] = 0;
    }
    ansV = 0;
    ansE = 0;
    add(s);
    while (1) {
      int ind = findMaxEV();
      if (ind) add(ind);
      if (ind == 0) break;
    }
    if (ansE > 0)
      if (ansV / ansE > megaAns) megaAns = ansV / ansE;
  }
  cout << fixed << setprecision(20) << megaAns;
  return 0;
}
