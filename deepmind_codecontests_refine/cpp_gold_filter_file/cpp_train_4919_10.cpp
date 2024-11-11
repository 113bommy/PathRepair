#include <bits/stdc++.h>
using namespace std;
long long n, s;
void solve() {
  cin >> n >> s;
  if (n == 1 && s == 2)
    puts("YES\n2\n1");
  else if (s - n <= 1 || s + 1 <= 2 * n)
    puts("NO");
  else {
    puts("YES");
    for (register int i = 1; i <= n - 1; i++) cout << "1 ";
    cout << s - n + 1 << endl << n;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
