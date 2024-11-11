#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<int> v;
void prime() {
  for (int i = 2; i <= n; i++) {
    c = 0;
    for (int k = 2; k < sqrt(i); k++) {
      if (i % k == 0) {
        c = 1;
        break;
      }
    }
    if (c == 0) v.push_back(i);
  }
}
int main() {
  cin >> n;
  prime();
  int y = v.size();
  for (int i = 0; i < y; i++) {
    for (int k = v[i]; k < n; k *= v[i]) {
      v.push_back(k);
    }
  }
  set<int> s(v.begin(), v.end());
  v.assign(s.begin(), s.end());
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}
