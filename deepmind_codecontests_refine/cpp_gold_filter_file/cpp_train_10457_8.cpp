#include <bits/stdc++.h>
using namespace std;
const long long INF = 200000000000000000LL;
int main() {
  int k, a, b;
  scanf("%d%d%d", &k, &a, &b);
  string s;
  cin >> s;
  int n = s.length();
  if (n < k * a || n > k * b) {
    cout << "No solution" << endl;
    return 0;
  }
  string ans = "";
  int last = -1, lines = 1;
  for (int i = 0; i <= n - 1; i++) {
    ans += s[i];
    if (last + a <= i && n - i - 1 <= (k - lines) * b && lines < k) {
      last = i;
      ans += "\n";
      lines++;
    }
  }
  cout << ans << endl;
}
