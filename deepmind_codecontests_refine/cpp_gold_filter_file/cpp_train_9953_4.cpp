#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n;
  cin >> n;
  long long ans = n;
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; i++) cin >> a, x[i] = make_pair(a, i);
  sort(x.begin(), x.end());
  for (int i = 1, j, k; i < n;)
    if (x[i].second < x[i - 1].second) {
      ans += (n - i);
      for (j = i + 1;
           j < n && x[j].first == x[i].first && x[j].second < x[i - 1].second;
           j++)
        ;
      for (k = j; k < n && x[k].first == x[i].first; k++)
        x[k].second = x[j - 1].second, ans--;
      i = k;
    } else
      ++i;
  cout << ans;
}
