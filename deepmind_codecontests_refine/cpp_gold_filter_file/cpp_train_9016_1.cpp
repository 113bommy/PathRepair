#include <bits/stdc++.h>
using namespace std;
void fun(long long a[], long long remain, long long total, long long n,
         long long m) {
  vector<long long> ans;
  long long i, j;
  for (i = 0; i < n && total > 0; i++) {
    if (a[i] % m == remain) {
      ans.push_back(a[i]);
      total--;
    }
  }
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
int main() {
  long long t, n, i, j, k, m;
  t = 1;
  while (t--) {
    cin >> n >> k >> m;
    map<long long, long long> x;
    long long a[n], flag = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      x[a[i] % m]++;
    }
    for (auto itr = x.begin(); itr != x.end(); itr++) {
      if (itr->second >= k) {
        flag = 1;
        cout << "Yes" << endl;
        fun(a, itr->first, k, n, m);
        break;
      }
    }
    if (flag == 0) cout << "No" << endl;
  }
}
