#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vt;
  for (int i = 1; i <= 4; i++) {
    int v;
    cin >> v;
    vt.push_back(v);
  }
  string str;
  cin >> str;
  int res = 0;
  for (int i = 0; i < str.size(); i++) {
    int a = (int)str.at(i) - 48 - 1;
    res += vt[a];
  }
  cout << res;
  return 0;
}
