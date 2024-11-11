#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0;
  cin >> n;
  for (long long i = 0; i < 9; i++)
    for (long long j = 0; j < 9; j++)
      if (i < 1 || j < 5) ans += min((long long)0, n - i - j + 1);
  cout << ans << endl;
}
