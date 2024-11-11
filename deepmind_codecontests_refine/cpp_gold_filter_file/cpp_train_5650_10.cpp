#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int suma = 0;
    int mayor = 0;
    int in;
    for (int i = 0; i < n; i++) {
      cin >> in;
      suma += in;
      mayor = max(in, mayor);
    }
    if (mayor > suma / 2 || suma % 2)
      cout << "T\n";
    else
      cout << "HL\n";
  }
  return 0;
}
