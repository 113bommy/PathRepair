#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, n;
  cin >> s >> n;
  vector<pair<int, int>> vect;
  int a, b;
  for (int(i) = (0); i < (n); i++) {
    cin >> a >> b;
    vect.push_back(make_pair(a, b));
  }
  sort(vect.begin(), vect.end());
  for (int(i) = (0); i < (n); i++) {
    if (vect[i].first <= s)
      s += vect[i].second;
    else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
