#include <bits/stdc++.h>
using namespace std;
int i, n, m, k, maxtotal, maxrand;
int Fr[1000005];
struct dinte {
  int rand, rezistenta;
};
dinte V[1005];
bool comp(dinte x, dinte y) {
  if (x.rand == y.rand) return x.rezistenta < y.rezistenta;
  return x.rand < y.rand;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie();
}
int main() {
  fast();
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    cin >> V[i].rand >> V[i].rezistenta;
    Fr[V[i].rand]++;
  }
  sort(V + 1, V + n + 1, comp);
  i = 1;
  while (i <= n && maxtotal <= k) {
    maxrand = V[i].rezistenta;
    if (maxtotal <= k) {
      maxtotal = maxtotal + maxrand;
      i = i + Fr[V[i].rand];
    } else
      break;
  }
  if (maxtotal > k)
    cout << k;
  else
    cout << maxtotal;
  return 0;
}
