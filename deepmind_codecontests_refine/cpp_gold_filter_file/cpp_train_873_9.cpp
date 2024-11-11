#include <bits/stdc++.h>
using namespace std;
string x;
int main() {
  int n, k;
  int ans = 0, z = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    for (int j = 0; j <= k; j++) {
      if (x.find(j + '0') != -1) ans++;
    }
    if (ans == k + 1) z++;
    ans = 0;
  }
  cout << z;
  return 0;
}
