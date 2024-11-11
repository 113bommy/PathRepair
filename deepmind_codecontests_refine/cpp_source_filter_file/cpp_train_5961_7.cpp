#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  cout << 3 * (n + 1) + 1 << endl;
  for (int i = 0; i <= n; i++) {
    cout << i << " " << i << endl;
    cout << i + 1 << " " << i << endl;
    cout << i << " " << i + 1 << endl;
  }
  cout << n << " " << n << endl;
  return 0;
}
