#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a[12] = {0, 8, 4, 4, 4, 4, 4, 4, 4, 4, 15, 4};
  int n;
  cin >> n;
  (n - 10 >= 0 && n - 10 <= 11) ? cout << a[n - 10] << endl : cout << 0 << endl;
  return 0;
}
