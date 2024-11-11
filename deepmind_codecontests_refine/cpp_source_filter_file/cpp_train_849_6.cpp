#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long pos = 0, neg = 1;
  cin >> n;
  int x, cur = 1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < 0) cur *= -1;
    if (cur < 0)
      neg++;
    else
      pos++;
  }
  cout << neg * pos << " " << n * (n + 1) / 2 - neg * pos << '\n';
  return 0;
}
