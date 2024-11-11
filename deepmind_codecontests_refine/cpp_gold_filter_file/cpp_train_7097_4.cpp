#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a;
  bool nula = 0;
  int neg = 0;
  long long sol = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a > 0) {
      sol += a - 1;
    } else if (a < 0) {
      sol += -a - 1;
      neg++;
    } else {
      nula = 1;
      sol++;
    }
  }
  if (neg % 2 == 1) {
    if (!nula) {
      sol += 2;
    }
  }
  cout << sol << '\n';
  return 0;
}
