#include <bits/stdc++.h>
using namespace std;
const int sizee = 105;
int N[sizee];
int n;
int main() {
  cin >> n;
  int od = 0, ev = 0;
  for (int i = 1; i <= n; i++) {
    cin >> N[i];
    if (N[i] & 1)
      ++od;
    else
      ++ev;
  }
  cout << max(od, ev);
  return 0;
}
