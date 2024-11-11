#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    if (b - a > 10) {
      cout << fixed << (int)ceil((double)(b - a) / 10) << '\n';
    } else if (a != b)
      cout << "1\n";
    else
      cout << "0\n";
  }
}
