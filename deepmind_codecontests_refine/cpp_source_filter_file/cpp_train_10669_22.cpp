#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int mas1[2001] = {0}, mas2[2001] = {0}, mas3[2002] = {0};
  for (int i = 1; i <= n; i++) {
    cin >> mas1[i];
    mas2[mas1[i]]++;
  }
  for (int i = 1; i <= n; i++) mas3[i] = mas3[i - 1] + mas2[i];
  for (int i = 1; i <= n; i++) {
    cout << 1 + mas3[n] - mas3[mas1[i]] << ' ';
  }
  return 0;
}
