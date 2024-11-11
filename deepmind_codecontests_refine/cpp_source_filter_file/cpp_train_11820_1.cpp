#include <bits/stdc++.h>
const int SZ = 1e3 + 5;
using namespace std;
bool a[SZ];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  for (int i = 0; i < SZ - 3; i++)
    if (a[i] && a[i + 1] && a[i + 1]) {
      cout << "YES";
      return 0;
    }
  cout << "NO";
}
