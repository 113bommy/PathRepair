#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, m, zero = 0;
  cin >> n;
  if (n == 1) {
    cin >> m;
    cout << m;
    exit(0);
  }
  vector<int> pos, neg;
  for (i = 0; i < n; i++) {
    cin >> m;
    if (m == 0)
      zero++;
    else if (m > 0)
      pos.push_back(m);
    else
      neg.push_back(-m);
  }
  if (pos.size()) {
    for (i = 0; i < pos.size(); i++) {
      cout << pos[i] << " ";
    }
  }
  if (pos.size() == 0 && neg.size() == 1 && zero > 0) {
    cout << "0";
    exit(0);
  }
  if (neg.size() > 0) {
    sort(neg.begin(), neg.end());
    for (i = neg.size() - 1; i >= 1; i--) {
      cout << -neg[i] << " ";
    }
    if (neg.size() % 2 == 0) {
      cout << -neg[0];
    }
  }
  return 0;
}
