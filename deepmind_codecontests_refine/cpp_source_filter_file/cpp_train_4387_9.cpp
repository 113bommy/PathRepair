#include <bits/stdc++.h>
using namespace std;
int main() {
  int count = 0;
  string m, o;
  cin >> m;
  string n;
  getline(cin, o);
  getline(cin, n);
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j <= n.length(); j++) {
      if (m[i] == n[j]) {
        count++;
      }
    }
  }
  if (count == 1) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
