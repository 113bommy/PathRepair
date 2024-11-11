#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e6 + 50;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int n;
long long a[maxn];
long long ans;
long long st[maxn];
int top = 0;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    while (top >= 2 && st[top - 1] >= st[top] && x >= st[top]) {
      ans += min(st[top - 1], x);
      top--;
    }
    st[++top] = x;
  }
  sort(st + 1, st + top + 1);
  for (int i = 1; i <= top - 2; i++) {
    ans += st[i];
  }
  cout << ans << endl;
  return 0;
}
