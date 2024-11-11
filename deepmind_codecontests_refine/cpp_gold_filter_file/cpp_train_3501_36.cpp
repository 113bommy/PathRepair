#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  string str;
  cin >> str;
  while (m--) {
    int p, q;
    char a, b;
    cin >> p >> q >> a >> b;
    for (i = p - 1; i <= q - 1; i++) {
      if (str[i] == a) {
        str[i] = b;
      }
    }
  }
  cout << str << endl;
}
