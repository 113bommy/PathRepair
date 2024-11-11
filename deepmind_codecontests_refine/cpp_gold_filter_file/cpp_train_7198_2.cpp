#include <bits/stdc++.h>
using namespace std;
struct student {
  long long a, b;
  bool operator<(const student& rhs) const { return a - b > rhs.a - rhs.b; }
} s[100010];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b;
  sort(s + 1, s + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (s[i].a - s[i].b) * i;
    ans += n * s[i].b - s[i].a;
  }
  cout << ans;
  return 0;
}
