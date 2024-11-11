#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, s = 0;
  cin >> a;
  int z[a];
  for (int i = 0; i < a; i++) cin >> z[i];
  sort(z, z + a);
  for (int i = 0; i < a; i++) {
    if (z[i] != z[i + 1]) {
      cout << z[i + 1];
      s++;
      break;
    }
  }
  if (s == 0) cout << "NO";
  return 0;
}
