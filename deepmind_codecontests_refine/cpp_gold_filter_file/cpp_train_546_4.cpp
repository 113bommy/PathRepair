#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, string> > V(n);
  for (register int i = (0); i < (int)(n); ++i)
    cin >> V[i].second >> V[i].first;
  sort((V).begin(), (V).end());
  vector<pair<int, string> > res;
  for (register int i = (0); i < (int)(n); ++i) {
    int pos = V[i].first;
    V[i].first = n - i;
    if (pos > ((int)(res).size())) {
      cout << -1 << "\n";
      return 0;
    }
    res.insert(res.begin() + pos, V[i]);
  }
  for (__typeof((res).begin()) it = (res).begin(); it != (res).end(); ++it)
    cout << it->second << " " << it->first << "\n";
  return 0;
}
