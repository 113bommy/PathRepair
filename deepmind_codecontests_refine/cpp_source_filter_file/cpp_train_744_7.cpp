#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  while (q--) {
    long long n;
    cin >> n;
    long long i, a[n], in;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++)
      if (a[i] == 1) in = i;
    for (i = in; i < (n + in - 1); i++)
      if (a[(i + 1) % n] < a[i % n]) break;
    if (i == (n + in)) {
      cout << "YES\n";
      continue;
    }
    for (i = in; i >= (in - n + 1); i--)
      if (a[(i + n) % n] > a[(i + n - 1) % n]) break;
    if (i == (in - n + 1)) {
      cout << "YES\n";
      continue;
    }
    cout << "NO";
    cout << "\n";
  }
  return 0;
}
