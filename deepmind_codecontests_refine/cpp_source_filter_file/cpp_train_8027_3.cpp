#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, j, sum = 0, c = 0, d = 0;
  cin >> n >> k;
  long long a[n];
  vector<int> v;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % k != 0) {
    cout << "NO";
  } else {
    for (i = 0; i < n; i++) {
      c = 0;
      d = 0;
      while (c < (sum / k) && i < n) {
        c += a[i];
        i++;
        d++;
      }
      if (c != (sum / k)) {
        cout << "NO";
        exit(0);
      }
      v.push_back(d);
      i--;
    }
    cout << "YES" << endl;
    for (int x : v) {
      cout << x << " ";
    }
  }
  return 0;
}
