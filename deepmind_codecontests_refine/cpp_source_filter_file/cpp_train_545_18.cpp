#include <bits/stdc++.h>
using namespace std;
using big = long long;
const int N = 2002000;
int n;
big a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cout << "1 1\n";
  cout << (-a[1]) << "\n";
  a[1] = 0;
  if (n == 1) {
    cout << "1 1\n";
    cout << "0\n";
    cout << "1 1\n";
    cout << "0\n";
  } else {
    cout << "2 " << n << "\n";
    for (int i = 2; i <= n; ++i) {
      int remainder = a[i] % n;
      big add = 1ll * remainder * (n - 1);
      cout << add << " ";
      a[i] += add;
    }
    cout << endl;
    cout << "2 " << n << "\n";
    for (int i = 2; i <= n; ++i) {
      assert(a[i] % n == 0);
      big add = -a[i];
      cout << add << " ";
      a[i] += add;
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
      assert(a[i] == 0);
    }
  }
  return 0;
}
