#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i += 4) s += "aabb";
  for (int i = 0; i < n; i++) cout << s[i];
}
