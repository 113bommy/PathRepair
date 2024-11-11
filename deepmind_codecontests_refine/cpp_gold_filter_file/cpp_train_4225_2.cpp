#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int ar[N];
set<int> S;
int odd = 1, even = 2;
int cnt[2] = {};
int main(void) {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> ar[i];
    if (S.count(ar[i]))
      ar[i] = -ar[i];
    else {
      S.insert(ar[i]);
      ++cnt[ar[i] % 2];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (ar[i] > 0) continue;
    if (cnt[0] < n / 2) {
      while (S.count(even)) even += 2;
      ar[i] = even;
      S.insert(even);
      even += 2;
      ++cnt[0];
      ++ans;
    } else {
      while (S.count(odd)) odd += 2;
      ar[i] = odd;
      S.insert(odd);
      odd += 2;
      ++cnt[1];
      ++ans;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (cnt[ar[i] % 2] > n / 2) {
      S.erase(ar[i]);
      int x = ar[i] % 2 ? even : odd;
      while (S.count(x)) x += 2;
      S.insert(x);
      --cnt[ar[i] % 2];
      ++cnt[ar[i] % 2 == 0];
      ar[i] = x;
      x += 2;
      if (x % 2)
        odd = x;
      else
        even = x;
      ++ans;
    }
  }
  if (odd - 2 > m || even - 2 > m) {
    cout << "-1\n";
    exit(0);
  }
  cout << ans << "\n";
  for (int i = 0; i < n; ++i) cout << ar[i] << " ";
  return 0;
}
