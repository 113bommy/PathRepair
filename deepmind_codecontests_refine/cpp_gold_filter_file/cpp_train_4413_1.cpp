#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, t;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  cin >> s >> t;
  int l = 0, r = 0;
  int temp2 = 0;
  if (t > s) {
    int rw = 0, lw = 0;
    while (temp2 != t - s) {
      rw += v[s + temp2 - 1];
      temp2++;
    }
    temp2 = 0;
    while (temp2 != s + n - t) {
      lw += v[(t + temp2 - 1) % n];
      temp2++;
    }
    temp2 = 0;
    cout << min(rw, lw);
  } else if (t < s) {
    temp2 = 0;
    int rw = 0, lw = 0;
    while (temp2 != s - t) {
      lw += v[s - temp2 - 2];
      temp2++;
    }
    temp2 = 0;
    while (temp2 != n - s + t) {
      rw += v[(s + temp2 - 1) % n];
      temp2++;
    }
    temp2 = 0;
    cout << min(rw, lw);
  } else
    cout << 0;
  return 0;
}
