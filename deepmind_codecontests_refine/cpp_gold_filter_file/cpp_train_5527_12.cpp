#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int t = 1, i, j;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    vector<long long int> v;
    v.push_back(a[0]);
    for (i = 1; i < n; i++) v.push_back(a[i] - a[i - 1]);
    v.push_back(m - a[n - 1]);
    long long int k = v.size();
    long long int pre[k];
    pre[0] = a[0];
    pre[1] = pre[0];
    for (i = 2; i < k; i++) {
      if (i & 1)
        pre[i] = pre[i - 1];
      else
        pre[i] = pre[i - 2] + v[i];
    }
    long long int su[k];
    su[k - 1] = v[k - 1];
    su[k - 2] = v[k - 2];
    for (i = k - 3; i >= 0; i--) {
      su[i] = su[i + 2] + v[i];
    }
    vector<long long int> ans;
    for (i = 0; i < k; i++) {
      if (v[i] > 1) {
        long long int pas;
        if (i == 0)
          pas = 0;
        else
          pas = pre[i - 1];
        pas += v[i] - 1;
        if (i % 2 == 1 && i + 2 < k) pas += su[i + 2];
        if (i % 2 == 0 && i + 1 < k) pas += su[i + 1];
        ans.push_back(pas);
      }
    }
    long long int al = 0;
    for (i = 0; i < k; i++) {
      if (i % 2 == 0) al += v[i];
    }
    ans.push_back(al);
    long long int ma = *max_element((ans).begin(), (ans).end());
    cout << ma << endl;
  }
  return 0;
}
