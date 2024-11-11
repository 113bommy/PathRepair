#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> m;
  vector<pair<int, int> > p;
  long long test, i, temp, sum = 0, k = 0;
  cin >> test;
  pair<int, int> tp;
  for (i = 0; i < test; i++) {
    cin >> temp;
    if (temp == i)
      sum += 1;
    else {
      p.push_back(make_pair(i, temp));
      m[i] = temp;
    }
  }
  for (i = 0; i < p.size(); i++) {
    tp = p[i];
    if (m[tp.first] == tp.second && m[tp.second] == tp.first) {
      k = 2;
      break;
    }
    if (m[tp.first] == tp.second || m[tp.second] == tp.first) k = 1;
  }
  cout << sum + k;
  return 0;
}
