#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool a[n];
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    a[i] = c == '*';
  }
  for (int i = 0; i < n - 4; ++i)
    for (int j = 1; i + j * 4 < n; ++j)
      for (int k = 0; k < 5; ++k)
        if (!a[i + k * j])
          break;
        else if (k == 3) {
          cout << "yes" << endl;
          return 0;
        }
  cout << "no" << endl;
  return 0;
}
