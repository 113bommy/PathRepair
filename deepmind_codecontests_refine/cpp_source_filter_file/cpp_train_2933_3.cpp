#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long mult(long long a, long long b, long long p = MOD) {
  return ((a % p) * (b % p)) % p;
}
long long add(long long a, long long b, long long p = MOD) {
  return (a % p + b % p) % p;
}
int sosdp[1024][10];
vector<pair<int, int> > minn[1024];
int main() {
  int n, m, cuanto, valor;
  cin >> n >> m;
  memset(sosdp, 0, sizeof sosdp);
  for (long long i = 0; i < n; i++) {
    cin >> cuanto;
    int mask = 0;
    for (long long j = 0; j < cuanto; j++) {
      cin >> valor;
      valor--;
      mask |= (1 << valor);
    }
    if ((mask & 1) == 0) sosdp[mask ^ 1][0]++;
    sosdp[mask][0]++;
  }
  for (long long i = 1; i < 9; i++) {
    for (long long mask = 0; mask < (1 << 9); mask++) {
      if ((1 << i) & mask)
        sosdp[mask][i] = sosdp[mask][i - 1] + sosdp[mask ^ (1 << i)][i - 1];
      else
        sosdp[mask][i] = sosdp[mask][i - 1];
    }
  }
  int valor2;
  for (long long i = 0; i < m; i++) {
    cin >> valor2;
    cin >> cuanto;
    int mask = 0;
    for (long long j = 0; j < cuanto; j++) {
      cin >> valor;
      valor--;
      mask |= (1 << valor);
    }
    minn[mask].push_back(pair<int, int>(valor2, i + 1));
  }
  for (long long i = 0; i < (1 << 9); i++) sort(minn[i].begin(), minn[i].end());
  int maxx = 0, resp = 1e8, posi, posj;
  for (long long i = 0; i < (1 << 9); i++) {
    for (long long j = 0; j < (1 << 9); j++) {
      if (i == j) {
        if (sosdp[(i | j)][8] >= maxx) {
          if (minn[i].size() > 1) {
            if (resp > minn[i][0].first + minn[i][1].first ||
                sosdp[(i | j)][8] > maxx) {
              resp = minn[i][0].first + minn[i][1].first;
              posi = minn[i][0].second;
              posj = minn[i][1].second;
            }
            maxx = sosdp[(i | j)][8];
          }
        }
      } else {
        if (sosdp[(i | j)][8] >= maxx) {
          if (minn[i].size() > 0 && minn[j].size() > 0) {
            if (resp > minn[i][0].first + minn[j][0].first ||
                sosdp[(i | j)][8] > maxx) {
              resp = minn[i][0].first + minn[j][0].first;
              posi = minn[i][0].second;
              posj = minn[j][0].second;
            }
            maxx = sosdp[(i | j)][8];
          }
        }
      }
    }
  }
  cout << posi << " " << posj << endl;
}
