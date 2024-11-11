#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % k != 0)
    cout << "NO\n";
  else {
    int num = sum / k;
    for (int i = 1; i < n; i++) {
      v[i] += v[i - 1];
    }
    int cnt = 0;
    vector<int> res;
    int q = 0;
    for (int i = 0; i < n; i++) {
      q++;
      if (v[i] % num == 0) {
        cnt++;
        res.push_back(q);
        q = 0;
      }
    }
    if (cnt == k) {
      cout << "YES\n";
      for (int i = 0; i < k; i++) cout << res[i] << " ";
    } else
      cout << "NO\n";
  }
  return 0;
}
