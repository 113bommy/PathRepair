#include <bits/stdc++.h>
using namespace std;
const int nn = 1e5 + 8;
int fre[nn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    fre[x]++;
  }
  bool ok = false;
  for (int i = 1; i <= 1e5; i++) ok |= (fre[i] & 1);
  if (ok)
    cout << "Conan";
  else
    cout << "Agasa";
}
