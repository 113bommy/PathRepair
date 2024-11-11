#include <bits/stdc++.h>
using namespace std;
int main() {
  int mb = 0;
  string m, b = "heidi";
  cin >> m;
  for (int i = 0; i < m.size(); i++) {
    if (m[i] == b[mb]) mb++;
  }
  if (mb == 5)
    cout << "YES";
  else
    cout << "NO";
}
