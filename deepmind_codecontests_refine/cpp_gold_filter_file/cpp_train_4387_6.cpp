#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  char a[2], b[2];
  cin >> a;
  for (int i = 0; i < 5; i++) {
    cin >> b;
    if (a[0] == b[0] || b[1] == a[1]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
