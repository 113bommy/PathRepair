#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int n;
int main() {
  cin >> n;
  vector<int> tmp;
  tmp.push_back(1);
  v.push_back(tmp);
  v.push_back(tmp);
  n--;
  int k = 2;
  while (true) {
    if (n >= v.size()) {
      n -= v.size();
      int t = k;
      for (int i = 0; i < v.size(); i++) {
        v[i].push_back(t++);
      }
      tmp.clear();
      for (int j = k; j < t; j++) {
        tmp.push_back(j);
      }
      k = t;
      v.push_back(tmp);
    } else
      break;
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " ";
    cout << endl;
  }
  return 0;
}
