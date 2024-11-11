#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, modi = 1e9 + 7;
  cin >> a >> b;
  long long int ans, ans2, ans3;
  ans = ((b * (b - 1)) / 2) % modi;
  ans2 = (b * ((a * (a + 1)) / 2) % modi) % modi;
  ans3 = (ans2 + a) % modi;
  ans = (ans * ans3) % modi;
  cout << ans << endl;
}
