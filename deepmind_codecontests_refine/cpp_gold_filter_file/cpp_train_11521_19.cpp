#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  bool b = false;
  if (n % 2) {
    b = true;
  } else {
    b = false;
  }
  if (b) {
    cout << "Ehab"
         << "\n";
  } else {
    cout << "Mahmoud"
         << "\n";
  }
  return 0;
}
