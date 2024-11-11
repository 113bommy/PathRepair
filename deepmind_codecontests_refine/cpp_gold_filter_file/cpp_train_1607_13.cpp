#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3];
  int b[3];
  for (int i = 0; i < 3; i++) cin >> a[i];
  for (int i = 0; i < 3; i++) cin >> b[i];
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    if (a[i] == b[i]) ans++;
  }
  if (ans >= 1)
    cout << "YES";
  else
    cout << "NO";
}
