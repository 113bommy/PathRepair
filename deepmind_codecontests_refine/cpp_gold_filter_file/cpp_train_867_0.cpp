#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
set<pair<int, int> > desc;
set<pair<int, int> > ascBound;
set<pair<int, int> > asc;
int a[100100];
int b[100100];
int aInv[100100];
int bInv[100100];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = (1); i < (n + 1); i++) {
    cin >> a[i];
    aInv[a[i]] = i;
  }
  for (int i = (1); i < (n + 1); i++) {
    cin >> b[i];
    bInv[b[i]] = i;
  }
  for (int x = (1); x < (n + 1); x++) {
    int i = aInv[x];
    int j = bInv[x];
    if (i <= j) {
      desc.insert(make_pair(j - i, j));
    } else {
      ascBound.insert(make_pair(j, j - i));
      asc.insert(make_pair(j - i, j));
    }
  }
  for (int delta = (0); delta < (n); delta++) {
    while (!desc.empty() && desc.begin()->first < delta) {
      int dij, j;
      tie(dij, j) = *desc.begin();
      desc.erase(desc.begin());
      ascBound.insert(make_pair(j, dij));
      asc.insert(make_pair(dij, j));
    }
    while (!ascBound.empty() && ascBound.begin()->first - delta < 1) {
      int dij, j;
      tie(j, dij) = *ascBound.begin();
      ascBound.erase(ascBound.begin());
      asc.erase(asc.find(make_pair(dij, j)));
      desc.insert(make_pair(dij + n, j + n));
    }
    int result = INT_MAX;
    if (!desc.empty()) result = min(result, abs(desc.begin()->first - delta));
    if (!asc.empty()) result = min(result, abs(asc.rbegin()->first - delta));
    cout << result << endl;
  }
}
