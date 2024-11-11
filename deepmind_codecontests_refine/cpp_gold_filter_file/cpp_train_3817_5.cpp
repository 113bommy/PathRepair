#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int z = 0, o = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') z++;
    if (s[i] == '1') o++;
  }
  if (o >= 1) cout << 1;
  for (int i = 0; i < z; i++) {
    cout << 0 << "";
  }
  cout << endl;
}
