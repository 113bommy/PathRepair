#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, m, inicio, final;
  char c1, c2;
  string s;
  cin >> c >> m >> s;
  for (int i = 0; i < m; i++) {
    cin >> inicio >> final >> c1 >> c2;
    inicio--;
    final--;
    if (inicio == final) {
      if (s[inicio] == c1) {
        s[inicio] = c2;
      }
    } else {
      for (int i = inicio; i < final; i++) {
        if (s[i] == c1) {
          s[i] = c2;
        }
      }
    }
  }
  cout << s << endl;
  return 0;
}
