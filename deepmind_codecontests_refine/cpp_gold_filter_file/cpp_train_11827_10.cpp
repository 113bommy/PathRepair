#include <bits/stdc++.h>
using namespace std;
string S[20];
long long tab[100000];
long long tab1[100000];
int main() {
  int n;
  long long S;
  cin >> n >> S;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  int l = 1, r = n;
  int ans1 = 0, ans2 = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    for (int i = 0; i < n; i++) {
      tab1[i] = tab[i] + 1ll * m * (i + 1);
    }
    sort(tab1, tab1 + n);
    long long s = 0;
    for (int i = 0; i < m; i++) s += tab1[i];
    if (s > S)
      r = m - 1;
    else {
      ans1 = m;
      ans2 = s;
      l = m + 1;
    }
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
