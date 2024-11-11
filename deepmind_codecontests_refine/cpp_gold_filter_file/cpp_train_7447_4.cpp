#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, h, k, a[100000], s = 0, v = 0;
  cin >> n;
  cin >> h;
  cin >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    s = s + v / k;
    v = v % k;
    if (v + a[i] > h) {
      v = 0;
      s = s + 1;
    }
    v = v + a[i];
  }
  s = s + v / k;
  v = v % k;
  if (v != 0) s = s + 1;
  cout << s << endl;
  return 0;
}
