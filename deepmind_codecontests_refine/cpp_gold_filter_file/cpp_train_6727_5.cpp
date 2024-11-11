#include <bits/stdc++.h>
using namespace std;
string a;
bool consonant(char x) {
  return (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u');
}
int main() {
  cin >> a;
  int k = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (k >= 2) {
      if (consonant(a[i]) && consonant(a[i - 1]) && consonant(a[i - 2])) {
        if (a[i] != a[i - 1] || a[i] != a[i - 2]) {
          cout << " ";
          k = 0;
        }
      }
    }
    cout << a[i];
    ++k;
  }
  cout << endl;
  return 0;
}
