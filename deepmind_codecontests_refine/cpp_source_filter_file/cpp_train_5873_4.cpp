#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;
int main() {
  vector<int> v[nax];
  vector<int> hotels;
  int prev[nax];
  int objtype[nax], n, j, maxcount, startindex, count;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> objtype[i];
  for (int i = 1; i <= n; i++) {
    cin >> prev[i];
    if (prev[i]) v[prev[i]].push_back(i);
    if (objtype[i]) hotels.push_back(i);
  }
  maxcount = 0;
  startindex = hotels[0];
  for (int i = 0; i < (int)hotels.size(); i++) {
    j = hotels[i];
    count = 0;
    while ((int)v[prev[j]].size() == 1) {
      j = prev[j];
      count++;
    }
    if (count > maxcount) {
      startindex = j;
      maxcount = count;
    }
  }
  cout << maxcount + 1 << "\n";
  int i = startindex;
  while (objtype[i] == 0) {
    cout << i << " ";
    i = v[i][0];
  }
  cout << i << "\n";
  return 0;
}
