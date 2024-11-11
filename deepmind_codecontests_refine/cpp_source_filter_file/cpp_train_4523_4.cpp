#include <bits/stdc++.h>
using namespace std;
long long int a[209];
vector<long long int> V1, V2;
int main() {
  ios_base::sync_with_stdio(0);
  long long int n, i, j, k, x, ans = 0, mx = -1, sum = 0, cnt;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      V1.clear();
      V2.clear();
      for (k = i; k <= j; k++) {
        V1.push_back(a[k]);
      }
      for (k = 0; k < i; k++) {
        V2.push_back(a[k]);
      }
      for (k = j + 1; k < n; k++) {
        V2.push_back(a[k]);
      }
      sort(V1.begin(), V1.end());
      sort(V2.begin(), V2.end());
      cnt = x;
      long long int z = V2.size() - 1;
      long long int sz = V1.size();
      sum = 0;
      for (long long int p = 0; p < sz; p++) {
        if (V2.size() > 0 && V2[V2.size() - 1] > V1[p] && cnt) {
          V1[p] = V2[V2.size() - 1];
          cnt--;
          V2.pop_back();
        }
        sum += V1[p];
      }
      mx = max(mx, sum);
    }
  }
  cout << mx << "\n";
  return 0;
}
