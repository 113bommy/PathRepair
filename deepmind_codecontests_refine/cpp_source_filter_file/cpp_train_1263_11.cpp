#include <bits/stdc++.h>
using namespace std;
void solve() {
  int b, k;
  cin >> b >> k;
  int res = 0;
  for (int i = 0; i < k - 1; ++i) {
    int a;
    cin >> a;
    res ^= (a % 2) && (k % 2);
  }
  int x;
  cin >> x;
  res ^= (x % 2);
  if (res)
    cout << "odd"
         << "\n";
  else
    cout << "even"
         << "\n";
}
int main() { solve(); };
