#include <bits/stdc++.h>
using namespace std;
long long n, d1, d2;
vector<long long> fib;
int main() {
  fib.push_back(1LL);
  fib.push_back(2LL);
  while (fib[fib.size() - 1] < (long long)1e18) {
    long long temp = fib[fib.size() - 1] + fib[fib.size() - 2];
    fib.push_back(temp);
  }
  int _;
  scanf("%d", &_);
  while (_--) {
    cin >> n;
    vector<int> pos;
    for (int i = fib.size() - 1; i >= 0; i--)
      if (n >= fib[i]) {
        pos.push_back(i);
        n -= fib[i];
      }
    int las = -1;
    d1 = 1LL;
    d2 = 0LL;
    for (int i = pos.size() - 1; i >= 0; i--) {
      long long t1 = d1 + d2;
      long long t2 = d2 * (pos[i] - las) / 2 + d1 * (pos[i] - las - 1) / 2;
      d1 = t1;
      d2 = t2;
      las = pos[i];
    }
    cout << d1 + d2 << endl;
  }
  return 0;
}
