#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long r;
  cin >> r;
  if (r % 2 == 0 || r < 5)
    cout << "NO"
         << "\n";
  else {
    cout << "1"
         << " " << (r - 3) / 2 << "\n";
  }
  return 0;
}
