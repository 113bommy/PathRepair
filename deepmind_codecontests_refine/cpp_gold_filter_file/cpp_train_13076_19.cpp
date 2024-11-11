#include <bits/stdc++.h>
using namespace std;
const long long N = 200022;
int n, ans;
string s;
int a[10];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) a[i] += s[i] - '0';
  }
  for (int i = 0; i < 10; i++) ans = max(ans, a[i]);
  cout << ans;
}
