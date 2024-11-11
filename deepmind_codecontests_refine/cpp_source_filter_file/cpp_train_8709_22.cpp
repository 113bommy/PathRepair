#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
str tout[4] = {"No", "Yes", "NO", "YES"};
const ll M18 = 1e18;
const int M9 = 1e9;
const int N = 1e5;
int main() {
  int n;
  cin >> n;
  cout << 6 - n;
  map<str, str> m;
  m["purple"] = "Power";
  m["green"] = "Time";
  m["blue"] = "Space";
  m["orange"] = "Soul";
  m["red"] = "Reality";
  m["yellow"] = "Mind";
  for (int i = (0); i < (n); i++) {
    str s;
    cin >> s;
    m[s] = "";
  }
  cout << m["purple"] << "\n";
  cout << m["green"] << "\n";
  cout << m["blue"] << "\n";
  cout << m["orange"] << "\n";
  cout << m["red"] << "\n";
  cout << m["yellow"];
}
