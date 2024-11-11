#include <bits/stdc++.h>
using namespace std;
int main() {
  int na, nb;
  cin >> na >> nb;
  int k, m;
  cin >> k >> m;
  int a[100005], b[100005];
  for (int i = 1; i <= na; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= nb; i++) {
    cin >> b[i];
  }
  for (int i = nb - m; i >= 1; i--) {
    if (b[i] > a[k]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
