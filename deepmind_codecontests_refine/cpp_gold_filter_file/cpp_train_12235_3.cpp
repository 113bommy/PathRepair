#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans;
int main() {
  cin >> n;
  ans += (long long)12 * pow(4, (n - 3));
  ans *= 2;
  if (n > 3) ans += (long long)36 * pow((long long)4, (n - 4)) * (n - 3);
  cout << ans << endl;
}
