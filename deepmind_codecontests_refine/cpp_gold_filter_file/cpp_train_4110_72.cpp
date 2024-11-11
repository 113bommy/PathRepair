#include <bits/stdc++.h>
using namespace std;
string en = "\n";
string t = "hello";
string Y = "YES\n";
string N = "NO\n";
int main() {
  long long X, R, m, a, b, c, d, x, y, z, w, t, n, k, p, q, r, sum, ct = 0,
                                                                    flag = 0;
  string s, s1 = "purple", s2 = "green", s3 = "blue", s4 = "orange",
            s6 = "yellow", s5 = "red", s7;
  set<long long> st;
  map<string, long long> mp;
  vector<long long> v1, v2;
  ct = 0;
  cin >> a >> b >> c >> d;
  p = max(((3 * a) / 10), ((250 * a - a * c) / 250));
  q = max(((3 * b) / 10), ((250 * b - b * d) / 250));
  if (p > q)
    cout << "Misha" << endl;
  else if (p < q)
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
}
