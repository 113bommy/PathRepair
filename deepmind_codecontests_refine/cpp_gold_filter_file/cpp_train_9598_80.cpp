#include <bits/stdc++.h>
using namespace std;
long long n;
void in() { cin >> n; }
void out() {
  long long a, b;
  cin >> a >> b;
  n -= a;
  n > b + 1 ? cout << b + 1 : cout << n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    in();
    out();
  }
  return 0;
}
