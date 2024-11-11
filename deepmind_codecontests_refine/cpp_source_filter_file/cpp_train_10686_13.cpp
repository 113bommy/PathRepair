#include <bits/stdc++.h>
using namespace std;
long long n, q;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int o = 0; o < q; o++) {
    int x;
    cin >> x;
    while (x % 2 == 0) x = n + x / 2;
    cout << (x + 1) / 2 << "\n";
  }
  return 0;
}
