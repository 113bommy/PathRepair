#include <bits/stdc++.h>
const int N = 1e3 + 5;
const long long maxn = 1e18;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
using namespace std;
int main() {
  map<string, string> mp;
  mp["scissors"] = "paper";
  mp["paper"] = "rock";
  mp["rock"] = "scissors";
  string a, b, c;
  cin >> a >> b >> c;
  if (mp[a] == b && mp[a] == c)
    cout << "F";
  else if (mp[b] == a && mp[b] == c)
    cout << "M";
  else if (mp[c] == a && mp[c] == b)
    cout << "S";
  else
    cout << "?";
}
