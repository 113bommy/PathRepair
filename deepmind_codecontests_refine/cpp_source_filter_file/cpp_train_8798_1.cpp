#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> mapp;
  vector<string> v;
  int n, t;
  cin >> n;
  t = n;
  string ss;
  for (int i = 0; i < n; i++) {
    cin >> ss;
    if (mapp[ss] != 0) t--;
    mapp[ss]++;
    v.push_back(ss);
  }
  for (int i = t; i >= 0; i--) {
    if (mapp[v[i]] >= 1) {
      cout << v[i] << endl;
      mapp[v[i]] = 0;
    }
  }
  return 0;
}
