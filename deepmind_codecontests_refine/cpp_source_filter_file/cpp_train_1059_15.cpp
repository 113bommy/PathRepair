#include <bits/stdc++.h>
using namespace std;
int digits(long long v) {
  long long ans = 0;
  while (v) v /= 10, ans++;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k, curr = 0, v = 0, i = 0;
    cin >> k;
    while (1) {
      v += digits(i);
      curr += v;
      if (curr > k) break;
      i++;
    }
    k -= (curr - v);
    if (!k)
      cout << (i - 1) % 10 << endl;
    else {
      string p;
      for (int j = 1; j < i; j++) p += to_string(j);
      cout << p[k - 1] << endl;
    }
  }
}
