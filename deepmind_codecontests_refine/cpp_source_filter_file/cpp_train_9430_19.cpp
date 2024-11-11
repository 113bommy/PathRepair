#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  string a, b, c;
  getline(cin, a);
  getline(cin, b);
  getline(cin, c);
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'u' or a[i] == 'i' or a[i] == 'a' or a[i] == 'e' or a[i] == 'o')
      t++;
  }
  if (t == 5) {
    t = 0;
    for (int i = 0; i < a.size(); i++) {
      if (b[i] == 'u' or b[i] == 'i' or b[i] == 'a' or b[i] == 'e' or
          b[i] == 'o')
        t++;
    }
    if (t == 7) {
      t = 0;
      for (int i = 0; i < a.size(); i++) {
        if (b[i] == 'u' or b[i] == 'i' or b[i] == 'a' or b[i] == 'e' or
            b[i] == 'o')
          t++;
      }
    }
    if (t == 5)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
