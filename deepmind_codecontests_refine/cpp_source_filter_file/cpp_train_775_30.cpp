#include <bits/stdc++.h>
using namespace std;
int n1, n2, k1, k2;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n1 >> n2 >> k1 >> k2;
  if (n1 < n2)
    cout << "Second\n";
  else
    cout << "First\n";
  return 0;
}
