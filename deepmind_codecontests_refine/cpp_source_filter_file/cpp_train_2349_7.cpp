#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long n = b;
  vector<long long> r(0);
  r.push_back(n);
  bool found = false;
  while (n) {
    bool op1 = false, op2 = false;
    if (n % 2 && (n - 1) % 10 == 0) {
      n = (n - 1) / 10;
      op1 = true;
    }
    if (n % 2 == 0) {
      n /= 2;
      op2 = true;
    }
    if (op1 || op2) {
      r.push_back(n);
      if (n == a) {
        found = true;
        break;
      }
    } else {
      break;
    }
  }
  if (found) {
    cout << "YES" << endl;
    cout << r.size() << endl;
    reverse(r.begin(), r.end());
    for (long long i = 0; i < r.size(); i++) {
      (i != r.size() - 1) ? cout << r[i] << " " : cout << r[i] << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
