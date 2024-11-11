#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, k1, k2, a[100001], b[100001], na, nb;
  cin >> na >> nb;
  cin >> k1 >> k2;
  for (int i = 1; i <= na; i++) cin >> a[i];
  for (int i = 1; i <= nb; i++) cin >> b[i];
  l = a[k1];
  for (int i = 1; i <= nb; i++)
    if (l < b[i])
      if (nb - i + 1 >= k2) {
        cout << "YES";
        return 0;
      }
  cout << "NO";
}
