#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a >> b;
  a--;
  cout << ((a + b) % n + n) % n + 1 << endl;
  return 0;
}
