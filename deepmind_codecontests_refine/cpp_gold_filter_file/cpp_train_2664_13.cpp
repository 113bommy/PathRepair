#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  std ::ios ::sync_with_stdio(false);
  string str = "ROYGBIV";
  int n;
  cin >> n;
  for (int i = 0; i < n - 3; i++) {
    cout << str[i % 4];
  }
  cout << "BIV";
  return 0;
}
