#include <bits/stdc++.h>
using namespace std;
string a;
int main() {
  int b;
  cin >> a;
  if (a[a.size()] < 10)
    b = (a[a.size() - 1]) % 4;
  else
    b = (a[a.size() - 1] + (a[a.size() - 2]) * 10) % 4;
  if (b == 0) cout << (1 + 1 + 1 + 1) % 5;
  if (b == 1) cout << (1 + 2 + 3 + 4) % 5;
  if (b == 2) cout << (1 + 2 * 2 + 3 * 3 + 4 * 4) % 5;
  if (b == 3) cout << (1 + 2 * 2 * 2 + 3 * 3 * 3 + 4 * 4 * 4) % 5;
  if (b == 4) cout << (1 + 2 * 2 * 2 * 2 + 3 * 3 * 3 * 3 + 4 * 4 * 4 * 4) % 5;
}
