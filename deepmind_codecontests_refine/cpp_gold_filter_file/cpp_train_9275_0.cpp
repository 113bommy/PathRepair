#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, p[N], cnt[N], win[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i], cnt[p[i]] = i;
  for (int i = n; i; i--) {
    for (int j = cnt[i]; j <= n; j += i)
      if (p[j] > i && !win[j]) win[cnt[i]] = true;
    for (int j = cnt[i]; j >= 1; j -= i)
      if (p[j] > i && !win[j]) win[cnt[i]] = true;
  }
  for (int i = 1; i <= n; i++) cout << (win[i] ? 'A' : 'B');
}
