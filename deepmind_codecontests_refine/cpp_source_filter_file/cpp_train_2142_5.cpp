#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, a, b;
  cin >> n >> k >> a >> b;
  char c1 = 'G';
  char c2 = 'B';
  if (b > a) {
    swap(c1, c2);
    swap(a, b);
  }
  if (((b + 1) * k) < a) {
    cout << "NO";
    return 0;
  }
  while (true) {
    for (int i = 0; i < k && a > 0 && a >= b; i++, a--) {
      cout << c1;
    }
    if (b) {
      cout << c2;
      b--;
    } else
      break;
  }
  return 0;
}
