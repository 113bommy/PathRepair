#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<int> s;
  for (int i = 0; i < 11; i++) {
    int a;
    cin >> a;
    s.push(a);
  }
  int cnt = 0;
  while (s.size()) {
    int p = s.top();
    double cur = double(s.top());
    s.pop();
    double ar = sqrt(abs(cur));
    double br = cur * cur * cur * 5;
    double r = ar + br;
    if (cnt < p) {
      cout << "f(" << p << ") = MAGNA NIMIS!" << endl;
    } else {
      cout << fixed << setprecision(2) << "f(" << p << ") = " << r << endl;
    }
    cnt++;
  }
}
