#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 17;
int n, a[maxn], b[maxn], lol, lil;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i], lol += a[i], lil += b[i];
  if ((lol & 1) ^ (lil & 1)) return cout << "-1" << endl, 0;
  if (lol & 1) {
    for (int i = 0; i < n; i++) {
      if ((a[i] & 1) != (b[i] & 1)) return cout << "1" << endl, 0;
    }
    return cout << "-1" << endl, 0;
  }
  cout << "0" << endl;
  return 0;
}
