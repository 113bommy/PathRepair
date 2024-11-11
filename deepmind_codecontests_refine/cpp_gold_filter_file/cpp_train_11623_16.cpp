#include <bits/stdc++.h>
using namespace std;
int const N = 5005;
int mod = 1000000007;
int main() {
  int v1, v2, v3, vm;
  cin >> v3 >> v2 >> v1 >> vm;
  if ((v1 > 2 * vm or vm > 2 * v1) or 2 * v3 <= 2 * vm or 2 * v2 <= 2 * vm)
    cout << -1 << endl;
  else {
    cout << v3 * 2 << endl;
    cout << v2 * 2 << endl;
    cout << max(vm, v1) << endl;
  }
  return 0;
}
