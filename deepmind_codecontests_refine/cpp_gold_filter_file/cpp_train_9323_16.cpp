#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, ans, pos[maxn], a, b, k;
char s[maxn];
int main() {
  cin >> n >> a >> b >> k;
  scanf("%s", s + 1);
  int d = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') d++;
    if (s[i] == '1') d = 0;
    if (d == b) {
      d = 0;
      pos[++ans] = i;
    }
  }
  ans -= a - 1;
  cout << ans << endl;
  for (int i = 1; i <= ans; ++i) {
    cout << pos[i] << " ";
  }
  return 0;
}
