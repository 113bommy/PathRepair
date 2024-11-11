#include <bits/stdc++.h>
using namespace std;
struct node {
  double c;
  int d;
  bool operator<(const node& p) const { return c < p.c; }
};
node r[1001];
bool v[1001] = {false};
int main() {
  int n, k, m, x;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> r[i].c;
    r[i].d = i;
  }
  cin >> m;
  int card = 0;
  double sum = 0.0;
  double Min = 10000000000.0, Max = 0.0;
  for (int i = 0; i < m; i++) {
    sum = 0.0;
    for (int j = 0; j < n / k; j++) {
      cin >> x;
      if (j == 0 && v[x - 1] == false) {
        card++;
      }
      sum += r[x - 1].c;
      v[x - 1] = true;
    }
    Max = max(Max, sum);
    Min = min(Min, sum);
  }
  if (card < k) {
    sort(r, r + n);
    int cunt = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
      if (v[r[i].d] == false) {
        sum += r[i].c;
        cunt++;
        if (cunt == n / k) {
          Min = min(Min, sum);
          break;
        }
      }
    }
    cunt = 0;
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (v[r[i].d] == false) {
        sum += r[i].c;
        cunt++;
        if (cunt == n / k) {
          Max = max(Max, sum);
          break;
        }
      }
    }
  }
  int u = n / k;
  printf("%.10llf %.10llf\n", Min / u, Max / u);
  return 0;
}
