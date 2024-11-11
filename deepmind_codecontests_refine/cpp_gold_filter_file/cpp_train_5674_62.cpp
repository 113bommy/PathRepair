#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n1, a, s, max;
  cin >> n >> n1;
  map<int, int> m;
  for (int i = 0; i < n1; i++) {
    max = -1;
    for (int j = 0; j < n; j++) {
      cin >> a;
      if (a > max) {
        s = j + 1;
        max = a;
      }
    }
    m[s]++;
  }
  max = 0;
  while (!m.empty()) {
    if (m.begin()->second > max) {
      max = m.begin()->second;
      s = m.begin()->first;
    }
    m.erase(m.begin());
  }
  cout << s;
}
