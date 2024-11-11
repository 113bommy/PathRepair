#include <bits/stdc++.h>
using namespace std;
vector<long long> V;
int main() {
  long long s, l, i;
  cin >> s >> l;
  for (i = l; i > 0 && s > 0; i--)
    if (s - (i & -i) >= 0) {
      s -= (i & -i);
      V.push_back(i);
    }
  if (s != 0)
    cout << -1;
  else {
    cout << V.size() << endl;
    for (i = 0; i < V.size(); i++) cout << V[i] << " ";
  }
  return 0;
}
