#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
vector<int> v;
int main() {
  int x, y, z;
  cin >> x >> y;
  for (int i = 0; i < x; i++) {
    cin >> z;
    m[z]++;
    if (m[z] == 1) {
      v.push_back(i);
    }
  }
  if (v.size() < y)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << v[0] + 1;
    for (int i = 1; i < v.size(); i++) {
      cout << " " << v[i] + 1;
    }
    cout << endl;
  }
}
