#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    int n;
    string w;
    cin >> n;
    cin >> w;
    for (int i = 0; i < n; i++) {
      cout << w[i];
    }
    cout << "\n";
  }
  return 0;
}
