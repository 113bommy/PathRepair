#include <bits/stdc++.h>
using namespace std;
int main() {
  double s, aux;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    aux = i;
    s += 1 / aux;
  }
  cout << setprecision(12) << s << "\n";
}
