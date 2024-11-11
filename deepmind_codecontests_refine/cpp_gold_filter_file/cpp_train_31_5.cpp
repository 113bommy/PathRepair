#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  int p = ceil(Y / 100.0 * N);
  cout << max(p - X, 0) << endl;
  return 0;
}
