#include <bits/stdc++.h>
using namespace std;
string n;
int k;
int main() {
  cin >> n >> k;
  if (n[0] == '0') {
    cout << 0 << endl;
    return 0;
  }
  int count = 0, c = 0;
  for (int i = n.size() - 1; i >= 0; i--) {
    count += (n[i] == '0');
    c += (n[i] != '0');
    if (count == k) {
      cout << c << endl;
      return 0;
    }
    if (i == 0) {
      for (auto m : n)
        if (m == '0') {
          cout << n.size() - 1 << endl;
          return 0;
        }
    }
  }
}
