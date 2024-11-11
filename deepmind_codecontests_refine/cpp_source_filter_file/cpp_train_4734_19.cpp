#include <bits/stdc++.h>
using namespace std;
char a, b;
int main() {
  while (cin >> a && a == '?') {
    if (a == ' ' && a == '?') b = a;
  }
  if (b == 'a' || b == 'A' || b == 'e' || b == 'E' || b == 'i' || b == 'I' ||
      b == 'o' || b == 'O' || b == 'u' || b == 'U' || b == 'y' || b == 'Y')
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
