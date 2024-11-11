#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200005;
int v[NMAX];
int cnt[NMAX];
int ct = 0;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = n; i >= 1; i--) {
    if (v[i] == 0) ct++;
    cnt[i] = ct;
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    if (v[i] == 1) sum += 1ll * cnt[i];
  cout << sum << '\n';
  return 0;
}
