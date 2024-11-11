#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  set<int, greater<int> > se;
  pair<int, int> c[1000001];
  int mate[401] = {0};
  cin >> n;
  int in;
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = 1; j < i; j++) {
      cin >> in;
      c[in] = make_pair(i, j);
      se.insert(in);
    }
  }
  for (set<int, greater<int> >::iterator it = se.begin(); it != se.end();
       it++) {
    if (mate[c[*it].first] == 0 && mate[c[*it].second] == 0) {
      mate[c[*it].first] = c[*it].second;
      mate[c[*it].second] = c[*it].first;
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    cout << mate[i] << " ";
  }
  return 0;
}
