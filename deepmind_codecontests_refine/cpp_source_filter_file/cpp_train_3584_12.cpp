#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 5) {
    cout << 3 << ' ' << 2 << ' ' << 1 << endl;
    cout << 2 << ' ' << 1 << ' ' << 2 << endl;
    cout << 1 << ' ' << 4 << ' ' << 1 << endl;
    cout << 4 << ' ' << 5 << ' ' << 1 << endl;
    cout << 3 << ' ' << 4 << endl;
    cout << 3 << ' ' << 5 << endl;
    return 0;
  } else {
    for (int i = 0; i < n / 2; i++)
      cout << i + 1 << ' ' << n / 2 + i + 1 << ' ' << 1 << endl;
    int w = 1;
    for (int i = n / 2; i < n - 1; i++, w += 2)
      cout << i + 1 << ' ' << i + 2 << ' ' << w << endl;
    for (int i = 0; i < n / 2 - 1; i++) cout << i + 1 << ' ' << i + 2 << endl;
    cout << 1 << ' ' << 3 << endl;
  }
  return 0;
}
