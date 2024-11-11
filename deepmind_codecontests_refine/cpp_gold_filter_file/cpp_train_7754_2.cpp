#include <bits/stdc++.h>
using namespace std;
long long n, m, xx, fix[10001], k = 1, t = 1;
int main() {
  cin >> n;
  for (int i = 1; i <= 1000000; i++) {
    fix[k] = 1;
    if (k + t <= n)
      k = k + t;
    else {
      k = ((k) + t) % n;
    }
    t++;
  }
  for (int i = 1; i <= n; i++)
    if (!fix[i]) {
      cout << "NO";
      return 0;
    }
  cout << "YES";
  return 0;
}
