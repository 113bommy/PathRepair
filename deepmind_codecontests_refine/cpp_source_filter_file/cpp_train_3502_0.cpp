#include <bits/stdc++.h>
using namespace std;
int find_dist(double x, double y, double x1, double y1) {
  double dist;
  x = abs(x1 - x);
  y = abs(y1 - y);
  dist = hypot(x, y);
  return dist;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  map<string, string> m;
  map<string, string> m2;
  int n, n2, i;
  cin >> n >> n2;
  string s, s2, s3;
  for (i = 0; i < n; i++) {
    cin >> s >> s2;
    m[s2] = s;
  }
  for (i = 0; i < n2; i++) {
    cin >> s >> s2;
    s3 = s2;
    s3 = s3.erase(s2.size() - 1);
    cout << s << " " << s2 << " "
         << "#" << m[s2] << endl;
  }
  return 0;
}
