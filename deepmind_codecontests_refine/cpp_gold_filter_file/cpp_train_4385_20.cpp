#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << " " << p.second;
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto& i : v) {
    out << i << "\n";
  }
  return out;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int legs = abs(x - y) * t1;
  int lift = abs(z - x) * t2 + abs(x - y) * t2 + 3 * t3;
  if (legs >= lift) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
