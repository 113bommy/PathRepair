#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int d;
  bool cIns, dIns;
  ios_base::sync_with_stdio(0);
  cin >> c >> d;
  cIns = c > 'a' && c < 'h';
  dIns = d > 1 && d < 8;
  if (cIns && dIns)
    cout << 8;
  else if (!cIns && !dIns)
    cout << 4;
  else
    cout << 6;
  cout << '\n';
  return 0;
}
