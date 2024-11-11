#include <bits/stdc++.h>
using namespace std;
int main() {
  string b;
  cin >> b;
  int n = b.size() - 1, p = 0;
  for (int i = 1; i < b.size(); i++)
    if (b[i] == '1') {
      p = 1;
      break;
    }
  if (n % 2 != 0)
    cout << (n / 2) + 1;
  else {
    if (p == 0)
      cout << (n / 2);
    else
      cout << (n / 2) + 1;
  }
  return 0;
}
