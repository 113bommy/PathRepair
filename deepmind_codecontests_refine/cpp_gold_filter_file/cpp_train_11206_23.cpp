#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long lx[43];
  if (k == 1)
    cout << "Yes\n";
  else {
    if (k > 42ll)
      cout << "No\n";
    else {
      lx[1] = 1;
      for (long long i = 2; i < 43; i++) {
        lx[i] = lx[i - 1] * (i / gcd(lx[i - 1], i));
      }
      if ((n + 1) % lx[k] == 0)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
}
