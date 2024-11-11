#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  long long v = 0, v2 = 0, answ = 0;
  for (long long i = 0, x; i < n; i++) {
    cin >> x;
    v += x % 2;
    v2 += x / 2;
    long long tmp = min(v, v2);
    answ += tmp;
    v2 -= tmp;
    v -= tmp;
  }
  answ += (v2 * 2) / 3;
  cout << answ;
}
