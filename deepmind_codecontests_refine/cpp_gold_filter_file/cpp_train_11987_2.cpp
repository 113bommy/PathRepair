#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  long long kk;
  while (cin >> n >> k) {
    kk = k * (k - 1);
    if (kk < n) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i < k; i++) {
      for (int j = i + 1; j <= k; j++) {
        cout << i << " " << j << endl;
        n--;
        if (!n) goto loop;
        cout << j << " " << i << endl;
        n--;
        if (!n) goto loop;
      }
    }
  loop:;
  }
  return 0;
}
