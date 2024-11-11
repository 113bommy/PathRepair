#include <bits/stdc++.h>
using namespace std;
const long double pie = 3.14159265358979;
const long long mod = 1e9 + 7;
string vow = "aeiou";
void solve(int test_case) {
  string f, m, s;
  cin >> f >> m >> s;
  map<string, string> beat;
  beat["rock"] = "scissor";
  beat["scissor"] = "paper";
  beat["paper"] = "rock";
  if (beat[f] == m && beat[f] == s)
    cout << "F";
  else if (beat[m] == f && beat[m] == s)
    cout << "M";
  else if (beat[s] == f && beat[s] == m)
    cout << "S";
  else
    cout << "?";
  cout << "\n";
}
int main() {
  int t = 1;
  for (int i = 0; i < t; i++) solve(i);
  return 0;
}
