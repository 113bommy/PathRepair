#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0;
char tmp;
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    if (tmp == 'B') ans = ans + (long long)(1LL << i);
  }
  cout << ans << endl;
  return 0;
}
