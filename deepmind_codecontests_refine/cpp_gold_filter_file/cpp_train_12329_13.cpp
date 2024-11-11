#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  long long respuesta = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      respuesta = pow(2, i) + respuesta;
    }
  }
  cout << respuesta;
  return 0;
}
