#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ac[n], c;
  long long a[n], s, ts;
  s = 0;
  c = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % 3 != 0) {
  } else {
    ts = s / 3;
    s = 0;
    for (int i = 0; i < n; i++) {
      s += a[i];
      if (s == ts)
        ac[i] = 1;
      else
        ac[i] = 0;
    }
    for (int i = 1; i < n; i++) ac[i] += ac[i - 1];
    s = 0;
    for (int i = n - 1; i > 1; i--) {
      s += a[i];
      if (s == ts) c += ac[i - 2];
    }
  }
  cout << c << endl;
  return 0;
}
