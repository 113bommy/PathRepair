#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  string a, b, c;
  cin >> a >> b >> c;
  map<char, int> k;
  k['A'] = 0;
  k['B'] = 0;
  k['C'] = 0;
  if (a[1] == '<') {
    k[a[0]]--;
    k[a[2]]++;
  } else {
    k[a[0]]++;
    k[a[2]]--;
  }
  if (b[1] == '<') {
    k[b[0]]--;
    k[b[2]]++;
  } else {
    k[b[0]]++;
    k[b[2]]--;
  }
  if (c[1] == '<') {
    k[c[0]]--;
    k[c[2]]++;
  } else {
    k[c[0]]++;
    k[c[2]]--;
  }
  int flag = 3;
  vector<pair<int, char>> ka(3);
  int i = 0;
  for (auto x : k) {
    if (x.second == -2) flag -= 2;
    if (x.second == 2) flag += 2;
    ka[i].first = x.second;
    ka[i].second = x.first;
    i++;
  }
  sort(ka.begin(), ka.end());
  if (flag != 4)
    cout << "Impossible" << endl;
  else {
    for (auto x : ka) cout << x.second;
    cout << endl;
  }
  return 0;
}
