#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long n, k;
  cin >> n >> k;
  unsigned long long a;
  unsigned long long o;
  unsigned long long mn = 10000000000000000;
  unsigned long long idx = 1;
  unsigned long long x;
  for (int i = 1; i <= k; i++) {
    cin >> a;
    o = n % a;
    if ((n % a) < mn) {
      mn = (n % a);
      idx = i;
      x = a;
    }
  }
  unsigned long long tms = n / x;
  cout << idx << " " << tms << endl;
}
