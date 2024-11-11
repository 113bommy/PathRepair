#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  int j = 1, i = 0, sum = 0;
  while (i < n) {
    while (v[i].second >= v[j].second && j < n) {
      j++;
      sum++;
    }
    i = j;
    j++;
  }
  cout << sum << endl;
  return 0;
}
