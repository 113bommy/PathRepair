#include <bits/stdc++.h>
using namespace std;
int main() {
  int na[100004];
  int nb[100004];
  int k, m, a, b;
  cin >> a >> b;
  cin >> k >> m;
  for (int i = 1; i <= a; i++) cin >> na[i];
  for (int i = 1; i <= b; i++) cin >> nb[i];
  if (na[k] < nb[b - m])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
