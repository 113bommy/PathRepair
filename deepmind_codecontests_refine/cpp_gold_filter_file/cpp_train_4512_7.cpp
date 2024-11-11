#include <bits/stdc++.h>
using namespace std;
bool good(int64_t a, int64_t b) {
  if (a == 0) return false;
  if (!good(b % a, a)) return true;
  int64_t c = b / a;
  return (c % (a + 1)) % 2 == 0;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int t;
  cin >> t;
  while (t--) {
    int64_t a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (good(a, b) ? "First" : "Second") << "\n";
  }
}
