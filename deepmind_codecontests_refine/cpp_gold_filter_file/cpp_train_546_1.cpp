#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, string> > v;
  vector<int> vv;
  for (int i = 0; i < n; i++) {
    string s;
    int t;
    cin >> s >> t;
    v.push_back(pair<int, string>(t, s));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i].first > i) {
      printf("-1");
      return 0;
    }
    int val = i - v[i].first + 1;
    for (int j = 0; j < i; j++)
      if (vv[j] >= val) vv[j]++;
    vv.push_back(val);
  }
  for (int i = 0; i < n; i++) cout << v[i].second << " " << vv[i] << endl;
  return 0;
}
