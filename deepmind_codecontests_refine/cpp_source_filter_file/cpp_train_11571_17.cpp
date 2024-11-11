#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, v, cost, i;
  cin >> n >> v;
  if (v >= (n - 1))
    cout << v;
  else {
    cost = v;
    for (i = 2; i <= n; i++) {
      v--;
      if ((n - i) <= v) {
        cout << cost;
        break;
      } else {
        cost += i;
        v++;
      }
    }
  }
  cout << "\n";
  return 0;
}
