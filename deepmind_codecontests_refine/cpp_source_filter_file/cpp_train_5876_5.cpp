#include <bits/stdc++.h>
using namespace std;
int main() {
  int j = 0;
  string a, b;
  cin >> a;
  cin >> b;
  for (int i = a.length() - 1; i > 0; i--) {
    if (a[i] == b[j]) {
      j++;
    } else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
