#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main() {
  int a, b, c, d, k, n, l = 0, r, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b;
    vector<int> q(b + 1);
    for (int j = 0; j < b; j++) {
      cin >> q[j];
      if (j % 2 == 1) {
        cout << -q[j] << " " << q[j - 1] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
