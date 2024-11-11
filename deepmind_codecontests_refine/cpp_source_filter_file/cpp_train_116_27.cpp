#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  bool fl = 0;
  int idxl = 0, idxr = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] < s[i - 1]) {
      fl = true;
      idxl = i - 1;
      idxr = i;
      break;
    }
  }
  if (fl == 1) {
    cout << "YES\n";
    cout << idxl << " " << idxr << "\n";
  } else
    cout << "NO\n";
  return 0;
}
