#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long ans = 1;
  cin >> n;
  for (int i = 2; i <= n; i++) ans += i * 6;
  cout << ans << endl;
}
