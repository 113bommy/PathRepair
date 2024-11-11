#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string a;
  cin >> a;
  int f[2000] = {};
  for (int i = 0; a[i] != '\0'; i++) {
    f[a[i]]++;
  }
  int k = min(
      f['B'],
      min(f['b'] / 2,
          min(f['u'] / 2, min(f['l'], min(f['a'] / 2, min(f['s'], f['r']))))));
  cout << k;
}
