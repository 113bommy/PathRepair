#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k;
  cin >> k;
  long long x = 1, prev = 1, curr = 2, ci = 0, pi = 10;
  while (x <= k) {
    if (ci == 9) {
      ci = 0;
      pi = 10;
      curr++;
      prev++;
    }
    x = x * curr / prev;
    ci++;
    pi--;
  }
  string s = "codeforces";
  if (k == 1)
    cout << s << endl;
  else {
    long long i = 0;
    while (i < ci) {
      long long y = curr;
      while (y--) {
        cout << s[i];
      }
      i++;
    }
    while (i < 10) {
      long long y = prev;
      while (y--) {
        cout << s[i];
      }
      i++;
    }
  }
  return 0;
}
