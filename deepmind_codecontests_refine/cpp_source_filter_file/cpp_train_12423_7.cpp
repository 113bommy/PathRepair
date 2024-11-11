#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  sort(b.rbegin(), b.rend());
  int j = 0;
  for (int i = 0; i < a.size(); i++) {
    int x = a[i], y = b[j];
    if (x < y) {
      a[i] = b[j];
      j--;
    }
  }
  cout << a << endl;
  return 0;
}
