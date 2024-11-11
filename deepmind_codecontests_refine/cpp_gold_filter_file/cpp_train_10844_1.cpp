#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  while (n--) {
    string a, b;
    cin >> a >> b;
    long long k = 0, f = 1;
    if (a.size() > b.size()) {
      cout << "NO" << endl;
      continue;
    }
    for (long long i = 0; i < b.size(); i++) {
      long long j = i + 1;
      long long cnt = 1;
      for (; j < b.size(); j++) {
        if (b[j] == b[i]) {
          cnt++;
        } else
          break;
      }
      long long cn = 0;
      for (; k < a.size(); k++) {
        if (a[k] == b[i]) {
          cn++;
        } else
          break;
      }
      if (cn == 0) {
        f = 0;
        break;
      }
      if (cn > cnt) {
        f = 0;
        break;
      }
      i = j - 1;
      if (i >= b.size() - 1 && k <= a.size() - 1) {
        f = 0;
        break;
      }
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
