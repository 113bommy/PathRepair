#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, l, a, ans = 0;
  cin >> k >> l;
  a = k;
  while (k * a <= l) {
    k *= a;
    ans++;
  }
  if (k == l)
    cout << "YES" << endl << ans;
  else
    cout << "NO";
}
