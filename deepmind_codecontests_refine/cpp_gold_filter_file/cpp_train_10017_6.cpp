#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int n, ev = 0, od = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      ev++;
    }
    if (a[i] % 2 != 0) {
      od++;
    }
  }
  if (od % 2 == 0) {
    cout << ev;
  } else {
    cout << od;
  }
  return 0;
}
