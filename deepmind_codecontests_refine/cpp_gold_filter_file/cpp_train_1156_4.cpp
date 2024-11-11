#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 2, j, k = 0, n, m, b = 1, c = 1, p = 1, flag = 0;
  cin >> n;
  m = n;
  int o = n;
  vector<int> v;
  set<int> s;
  if (n == 1) {
    cout << 1 << " " << 0;
    return 0;
  }
  while (n > 1) {
    while (n % i == 0) {
      n = n / i;
      v.push_back(i);
      s.insert(i);
    }
    i++;
  }
  b = 1, c = 1;
  for (i = 0; i < v.size() - 1; i++) {
    if (v[i] == v[i + 1]) {
      c++;
      if (c > b) b = c;
    } else
      c = 1, flag = 1;
  }
  set<int>::iterator it;
  for (it = s.begin(); it != s.end(); ++it) p *= (*it);
  if (s.size() * b != v.size()) {
    for (i = 0; i < b + 1; i++) {
      if (b <= pow(2, i)) {
        k = i;
        break;
      }
    }
    cout << p << " " << k + 1;
  } else if (s.size() == v.size())
    cout << p << " " << 0;
  else {
    c = b;
    k = 0;
    while (b > 1) {
      b = (b / 2 + b % 2);
      k++;
    }
    int j = pow(p, (1 << k));
    if (j == m - 1) j++;
    if (j != m) k++;
    cout << p << " " << k;
  }
}
