#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int c = 0;
  int q = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] == a[i + 1]) {
      c++;
    } else
      c = 0;
    if (c == 7) {
      q = 1;
      break;
    }
  }
  if (q == 1)
    cout << "YES";
  else
    cout << "NO";
}
