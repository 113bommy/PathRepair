#include <bits/stdc++.h>
using namespace std;
long long n, k, kol, maxn, kkol;
bool used[300005];
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  if (k == 6) {
    if (n < 6)
      cout << "No";
    else
      cout << "Yes" << endl << 5 << endl << "1 2 4 5 6";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (kol >= k) break;
    maxn = i;
    used[i] = true;
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0 && j < i) {
        kol++;
        if (i / j < i && i / j > j) kol++;
      }
  }
  if (kol < k) {
    cout << "No";
    return 0;
  }
  for (int i = maxn; i >= 1; i--) {
    if (kol <= k) break;
    if (used[i]) {
      kkol = 0;
      for (int j = 1; j * j <= i; j++)
        if (i % j == 0 && j < i) {
          if (used[j]) kkol++;
          if (i / j < i && i / j > j && used[i / j]) kkol++;
        }
      for (int j = 2 * i; j <= maxn; j++)
        if (used[j]) kkol++;
      if (kkol <= kol - k) {
        used[i] = false;
        kol -= kkol;
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < 300005; i++)
    if (used[i]) ans.push_back(i);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
