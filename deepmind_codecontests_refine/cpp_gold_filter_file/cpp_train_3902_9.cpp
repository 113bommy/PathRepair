#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  int c = 0;
  int k = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i += 2) {
    int j = 0;
    while (j < m) {
      cout << "#";
      j++;
    }
    cout << endl;
    k = i + 1;
    if (k < n) {
      c++;
      if (c % 2 != 0) {
        int j = 0;
        while (j < m - 1) {
          cout << ".";
          j++;
        }
        cout << "#" << endl;
      } else {
        int j = 1;
        cout << "#";
        while (j < m) {
          cout << ".";
          j++;
        }
        cout << endl;
      }
    }
  }
  return 0;
}
