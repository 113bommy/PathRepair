#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, a, b;
  cin >> n >> a >> b;
  if (a == n - 1 && b == 0) {
    if (n != 1) {
      cout << "-1" << endl;
    } else {
      cout << "1" << endl;
    }
    return 0;
  }
  vector<unsigned long long int> r;
  r.push_back(1);
  unsigned long long int s = 1;
  if (b == 0) {
    r.push_back(1);
    s = 2;
  }
  for (int i = 0; i < b; i++) {
    r.push_back(r.back() * 2);
    s += s + 1;
  }
  for (int i = 1; i < a; i++) {
    r.push_back(r.back() + 1);
  }
  r.resize(n, r.back());
  if (r.back() > 50000) {
    cout << "-1" << endl;
    return 0;
  } else {
    for (int i = 0; i < r.size(); i++) cout << r[i] << " ";
  }
  return 0;
}
