#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, b;
  int n, m;
  cin >> r >> b;
  for (int i = 0; i < r + b; i++) {
    cin >> n >> m;
  }
  if (r == b) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
