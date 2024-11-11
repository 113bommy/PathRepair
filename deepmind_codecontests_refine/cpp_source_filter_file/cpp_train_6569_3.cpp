#include <bits/stdc++.h>
using namespace std;
struct seg {
  long long l, r;
} s[200005];
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0;
  long long rest = m;
  for (int i = 0; i < n; i++) {
    cin >> s[i].l >> s[i].r;
  }
  int index = 0;
  long long temp = s[index].r - s[index].l;
  for (int i = 1; i < n; i++) {
    long long gap = s[i].l - s[i - 1].r;
    while (rest < gap) {
      ans = max(ans, temp + rest);
      index++;
      if (index == i) break;
      rest += s[index].l - s[index - 1].r;
      temp -= s[index].l - s[index - 1].l;
    }
    if (index == i) {
      rest = m;
      temp = s[i].r - s[i].l;
      continue;
    }
    rest -= gap;
    temp += s[i].r - s[i - 1].r;
    ans = max(ans, rest + temp);
  }
  ans = max(ans, temp + rest);
  cout << ans << '\n';
  return 0;
}
