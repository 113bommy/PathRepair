#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  if (m % 2 != 0) {
    int x = (m + 1) / 2;
    v.push_back(x);
    for (int i = 1; i < x; i++) {
      v.push_back(x - i);
      v.push_back(x + i);
    }
  } else {
    int x = m / 2;
    v.push_back(x);
    for (int i = 1; i < x; i++) {
      v.push_back(x - i);
      v.push_back(x + i);
    }
    v.push_back(m);
  }
  for (int i = 0; i < n; i++) cout << v[i % m] << endl;
}
