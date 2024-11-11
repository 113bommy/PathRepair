#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool *f = new bool[n];
  char ch;
  for (int i = 0; i < n; ++i) {
    cin >> ch;
    f[i] = (ch == '*');
  }
  int count;
  for (int d = 1; d <= n / 5 + 1; ++d) {
    for (int start = 0; start < d; ++start) {
      count = 0;
      for (int i = start; i < n; i += d) {
        if (f[i]) {
          count++;
          if (count == 5) {
            cout << "yes" << endl;
            return 0;
          }
        } else {
          count = 0;
        }
      }
    }
  }
  cout << "no" << endl;
  return 0;
}
