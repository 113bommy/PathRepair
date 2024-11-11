#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int count = 0;
  int j = 1;
  while (j <= n) {
    if (j % 2 == 1) {
      for (int i = 0; i < m; i++) cout << "#";
      count++;
    } else if (j % 2 == 0) {
      if (count % 2 == 1) {
        for (int i = 0; i < m - 1; i++) cout << ".";
        cout << "#";
      } else if (count % 2 == 0) {
        cout << "#";
        for (int i = 1; i < m - 1; i++) cout << ".";
      }
    }
    j++;
    cout << endl;
  }
  return 0;
}
