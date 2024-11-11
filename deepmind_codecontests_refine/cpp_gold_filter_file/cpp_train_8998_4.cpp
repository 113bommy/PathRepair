#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  int a;
  cin >> n;
  if (n.size() > 1)
    a = (int(n[n.size() - 1]) - 48 + (int(n[n.size() - 2]) - 48) * 10) % 4;
  else
    a = (int(n[n.size() - 1]) - 48) % 4;
  if (a == 1 || a == 2 || a == 3) cout << 0;
  if (a == 0) cout << 4;
  return 0;
}
