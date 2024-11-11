#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cout << endl;
    for (int j = 0; j < n; j++) {
      if (i == j)
        cout << m << " ";
      else
        cout << "0 ";
    }
  }
  return 0;
}
