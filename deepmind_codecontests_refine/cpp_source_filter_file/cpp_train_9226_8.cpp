#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n;
  cin >> n;
  bool ans[101];
  for (int i = 0; i <= 100; ++i) ans[i] = 0;
  for (int i = 0; i * 3 <= 100; ++i)
    for (int j = 0; i * 3 + j * 7 <= 100; ++j) ans[i * 3 + j * 7] = 1;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (ans[a])
      cout << "YES\n";
    else
      cout << "NO";
  }
}
