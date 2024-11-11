#include <bits/stdc++.h>
using namespace std;
int V1, V2, V3, T1, T2, T3, Vm;
int main() {
  cin >> V1 >> V2 >> V3 >> Vm;
  if (V3 > 2 * Vm || Vm > 2 * V3) {
    cout << -1;
    return 0;
  }
  T3 = max(Vm, V3);
  if (T3 >= V2) {
    cout << -1;
    return 0;
  }
  T2 = min(2 * V2, max(V2, 2 * T3 + 1));
  T1 = min(2 * V1, max(V1, T2 + 1));
  cout << T1 << endl << T2 << endl << T3;
  return 0;
}
