#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<int> lp(101, 0);
  vector<int> pr;
  for (int i = 2; i <= 100; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= 100;
         ++j)
      lp[i * pr[j]] = pr[j];
  }
  int n;
  cin >> n;
  vector<int> v(n), a(101, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    if (lp[v[i]] == v[i] && a[i] == 0)
      a[v[i]]++;
    else if (v[i] == 1)
      a[1]++;
    else {
      int k = v[i];
      for (int j = 1; j <= k; ++j) {
        if (k % j == 0) {
          if (a[j] > 0)
            break;
          else if (j == k)
            a[j]++;
        }
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i < 101; ++i) {
    if (a[i] > 0) cnt++;
  }
  cout << cnt << endl;
}
