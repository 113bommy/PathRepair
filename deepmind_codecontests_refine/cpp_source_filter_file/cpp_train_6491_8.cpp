#include <bits/stdc++.h>
using namespace std;
long long pi(int n) {
  long long x = 1;
  for (int i = 0; i < n; i++) {
    x *= 10;
  }
  return x;
}
int main() {
  string p;
  long long d, temp, sum = 0, res;
  cin >> p >> d;
  for (int i = 1; i <= p.size(); i++) {
    if (p[p.size() - i] != '9') {
      temp = p[p.size() - i] - '0';
      temp++;
      temp *= pi(i - 1);
      if (temp <= d) {
        d -= temp;
        stringstream buff(p);
        buff >> res;
        res -= temp;
        stringstream b;
        b << res;
        p = b.str();
      } else {
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
