#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, a, b;
  cin >> n >> a >> b;
  cout << 1 + (((n * 500) + a + b - 1) % n);
  return 0;
}
