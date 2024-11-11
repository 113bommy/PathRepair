#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int s, n;
  cin >> s >> n;
  vector<pair<int, int> > ve;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ve.push_back(make_pair(a, b));
  }
  sort(ve.begin(), ve.end());
  int flag = 1;
  for (int i = 0; i < n; i++) {
    if (s < ve[i].first) {
      flag = 0;
      break;
    } else {
      s += ve[i].second;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
