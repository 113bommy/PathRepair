#include <bits/stdc++.h>
using namespace std;
string a, b;
map<char, vector<int> > m;
void check(long long &f) {
  int prev = -1;
  for (int i = 0; i < (int)b.size(); i++) {
    int j = m[b[i]][0];
    vector<int>::iterator ind =
        upper_bound(m[b[i]].begin(), m[b[i]].end(), prev);
    if (ind != m[b[i]].end())
      prev = (*ind);
    else {
      f++;
      prev = j;
    }
  }
}
int main() {
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) m[a[i]].push_back(i);
  for (int i = 0; i < b.size(); i++)
    if (!m.count(b[i])) {
      cout << -1 << endl;
      return 0;
    }
  long long res = 0;
  check(res);
  cout << res << endl;
  return 0;
}
