#include <bits/stdc++.h>
using namespace std;
const int Nmax = 100000, Mmax = 100000;
int cities[Nmax], towers[Mmax];
long long closest[Nmax];
int bsbig(int i, int m) {
  int st = 0, dr = m - 1, sol = 100001;
  while (st <= dr) {
    int mijl = (st + dr) / 2;
    if (towers[mijl] > cities[i]) {
      sol = mijl;
      dr = mijl - 1;
    } else {
      st = mijl + 1;
    }
  }
  return sol;
}
int bssmall(int i, int m) {
  int st = 0, dr = m - 1, sol = 100001;
  while (st <= dr) {
    int mijl = (st + dr) / 2;
    if (towers[mijl] < cities[i]) {
      sol = mijl;
      st = mijl + 1;
    } else {
      dr = mijl - 1;
    }
  }
  return sol;
}
bool cmp(int x, int y) { return (x > y); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> cities[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> towers[i];
  }
  for (int i = 0; i < n; i++) {
    if (bsbig(i, m) == 100001) {
      closest[i] = cities[i] - towers[bssmall(i, m)];
    } else if (bssmall(i, m) == 100001) {
      closest[i] = towers[bsbig(i, m)] - cities[i];
    } else {
      closest[i] = min(cities[i] - towers[bssmall(i, m)],
                       towers[bsbig(i, m)] - cities[i]);
    }
  }
  sort(closest, closest + n, cmp);
  cout << closest[0];
  return 0;
}
