#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cout << 7 + (n - 1) * 3 << endl;
  cout << 0 << " " << 0 << endl;
  cout << 0 << " " << 1 << endl;
  cout << 1 << " " << 0 << endl;
  cout << 1 << " " << 1 << endl;
  cout << 1 << " " << 2 << endl;
  cout << 2 << " " << 0 << endl;
  cout << 2 << " " << 1 << endl;
  for (int i = 2; i <= n; i++) {
    cout << i << " " << i + 1 << endl;
    cout << i + 1 << " " << i + 1 << endl;
    cout << i + 1 << " " << i << endl;
  }
  return 0;
}
