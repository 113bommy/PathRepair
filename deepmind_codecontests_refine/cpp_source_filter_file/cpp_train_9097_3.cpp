#include <bits/stdc++.h>
using namespace std;
struct xx {
  int x, y;
} a[9];
bool cmp(xx a, xx b) { return (a.x < b.x || (a.x == b.x && a.y < b.y)); }
int l[100000];
long long x, t, ans;
int main() {
  int i;
  cin >> x;
  i = 3;
  while (x % i == 0) i *= 3;
  ans = x / i + 1;
  cout << ans << endl;
}
