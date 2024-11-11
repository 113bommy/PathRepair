#include <bits/stdc++.h>
using namespace std;
string tos(int ias) {
  stringstream out;
  out << ias;
  return out.str();
}
int toi(string sai) {
  istringstream in(sai);
  int ans;
  in >> ans;
  return ans;
}
int main() {
  int k, a, b, v, res = 0;
  cin >> k >> a >> b >> v;
  while (true) {
    if (b > 0) {
      if (b >= v) {
        a -= (k * v);
        b -= (k - 1);
      } else {
        a -= (v * (b + 1));
        b = 0;
      }
      res++;
    } else {
      res += a / v;
      a -= (a / v) * v;
      if (a <= v && a > 0) res++;
      break;
    }
    if (a <= 0) break;
  }
  cout << res << endl;
}
