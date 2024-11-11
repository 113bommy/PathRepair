#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 3;
vector<long long> prim;
vector<pair<long long, long long> > a[N];
long long n, m, x[N * 100];
void civ() {
  prim.push_back(0);
  prim.push_back(2);
  for (int i = 3; i <= 1e7; i += 2) {
    if (!x[i]) {
      prim.push_back(i);
      for (int j = i + i; j <= 1e7; j += i) x[j]++;
    }
  }
}
int main() {
  civ();
  cin >> n >> m;
  for (int i = n, j = 1; i >= 2; i--, j++)
    a[1].push_back(make_pair(i, prim[j] - prim[j - 1]));
  long long i = 2, j = 3;
  m -= n - 1;
  while (m--) {
    if (j == n + 1) {
      i++;
      j = i + 1;
    }
    a[i].push_back(make_pair(j, 1e9));
    j++;
  }
  cout << 2 << " " << prim[n - 1] << endl;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < a[i].size(); j++)
      cout << i << " " << a[i][j].first << " " << a[i][j].second << endl;
}
