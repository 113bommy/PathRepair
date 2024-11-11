#include <bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
int main() {
  cin >> n >> m;
  cin >> s1 >> s2;
  string corners = "";
  corners += s1.front();
  corners += s2.front();
  corners += s1.back();
  corners += s2.back();
  if (corners == "<v>^" || corners == ">v<^")
    cout << "YES\n";
  else
    cout << "NO\n";
}
