#include <bits/stdc++.h>
using namespace std;
int n, k, z[1000005], d[1000005];
string second;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  cin >> second;
  if (k == 1) {
    for (int i = 0; i < n; i++) cout << 1;
    cout << endl;
    return 0;
  }
  int l = 0, r = 0;
  for (int i = 1; i < n; i++)
    if (i > r) {
      l = r = i;
      while (r < n && second[r] == second[r - l]) r++;
      z[i] = r - l;
      r--;
    } else {
      int t = z[i - l];
      if (t < r - i + 1)
        z[i] = t;
      else {
        l = i;
        while (r < n && second[r] == second[r - l]) r++;
        z[i] = r - l;
        r--;
      }
    }
  z[0] = n;
  for (int i = 1; i < n; i++) {
    if (i * k >= n) break;
    int j = i, t = 0;
    while (j <= (k - 1) * i) {
      if (z[j] < i) {
        t = 1;
        break;
      }
      j += i;
    }
    if (!t) {
      d[k * i - 1]++, d[k * i]--;
      if (z[k * i]) d[k * i]++, d[k * i + min(i, z[k * i])]--;
    }
  }
  for (int i = 1; i < n; i++) d[i] += d[i - 1];
  for (int i = 0; i < n; i++)
    if (d[i])
      cout << 1;
    else
      cout << 0;
  cout << endl;
  return 0;
}
