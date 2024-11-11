#include <bits/stdc++.h>
using namespace std;
long long n, p;
int k, i, dif, poz, j;
map<int, int> M;
multiset<int> S;
multiset<int>::iterator it;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  p = 62;
  int nr = 0;
  while (n) {
    if (n >= (1LL << p)) {
      n = n - (1LL << p);
      M[p] = 1;
      nr++;
    }
    p--;
  }
  dif = k - nr;
  if (dif < 0) {
    cout << "No\n";
    return 0;
  } else
    cout << "Yes\n";
  poz = 62;
  while (dif) {
    if (M[poz] <= dif) {
      M[poz - 1] = M[poz - 1] + 2 * M[poz];
      dif -= M[poz];
      M[poz] = 0;
    } else
      break;
    poz--;
  }
  for (i = 62; i >= -62; i--)
    for (j = 1; j <= M[i]; j++) S.insert(i);
  while (dif) {
    nr = *S.begin();
    S.erase(S.begin());
    S.insert(nr - 1);
    S.insert(nr - 1);
    dif -= 2;
  }
  for (it = S.end(), it--; it != S.begin(); it--) {
    cout << *it << " ";
  }
  cout << *S.begin();
  return 0;
}
