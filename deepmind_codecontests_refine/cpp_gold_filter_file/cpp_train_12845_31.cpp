#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, k, t;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      t++;
    }
  }
  if (t <= k) {
    cout << "no solution";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cout << 0 << " " << i << endl;
  }
}
