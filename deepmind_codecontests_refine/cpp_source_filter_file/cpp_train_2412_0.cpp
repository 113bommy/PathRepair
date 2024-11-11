#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n % 2 && n > 3) {
    cout << 1 << " " << ((n - 3) / 2) << endl;
  } else {
    cout << "NO";
  }
  return 0;
}
