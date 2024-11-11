#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, md = 1e9 + 7, ans = 1, s = 1;
  cin >> n;
  for (int i = 0; i < n * 3; ++i, ans = (ans * 3) % md)
    ;
  for (int i = 0; i < n; ++i, s = (s * 7) % md)
    ;
  cout << (ans - s + md) % md << '\n';
  return 0;
}
