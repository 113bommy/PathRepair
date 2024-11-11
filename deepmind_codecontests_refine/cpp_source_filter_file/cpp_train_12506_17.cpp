#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    int n;
    string second;
    cin >> n >> second;
    if (n == 2) {
      if (second[0] == second[1]) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        cout << "2\n" << second[0] << " " << second[1] << "\n";
      }
    } else {
      cout << "YES\n";
      cout << "2\n";
      cout << second[0] << " ";
      for (int i = 1; i < n; ++i) cout << second[i];
      cout << "\n";
    }
  }
  return 0;
}
