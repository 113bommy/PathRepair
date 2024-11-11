#include <bits/stdc++.h>
using namespace std;
int solve(long long x) {
  if (x <= 3) return 0;
  if (x <= 15) return 1;
  if (x <= 81) return 2;
  if (x <= 6723) return 0;
  if (x <= 50625) return 3;
  if (x <= 2562991875LL) return 1;
  return 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  bool res = 0;
  int n;
  long long x;
  cin >> n;
  while (n--) {
    cin >> x;
    res ^= solve(x);
  }
  if (res == 0)
    cout << "Rublo\n";
  else
    cout << "Furlo\n";
  return 0;
}
