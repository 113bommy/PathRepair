#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string colors;
  cin >> colors;
  vector<int> col(n);
  for (int i = 0; i < n; i++) col[i] = (colors[i] == 'W' ? 0 : 1);
  int p = col[0];
  int k = 0;
  vector<int> op;
  for (int i = 1; i < n - 1;) {
    if (col[i] == p)
      i += 1;
    else {
      col[i] = p;
      col[i + 1] = (col[i + 1] == 1 ? 0 : 1);
      op.push_back(i + 1);
      i += 1;
      k += 1;
    }
  }
  if (col[n - 1] != p) {
    if (n - 1 % 2 == 1)
      cout << -1 << endl;
    else {
      cout << k + (n - 1) / 2 << endl;
      for (int el : op) cout << el << " ";
      for (int i = 1; i < n - 1; i += 2) cout << i << " ";
      cout << endl;
    }
  } else {
    cout << k << endl;
    for (int el : op) cout << el << " ";
    cout << endl;
  }
}
