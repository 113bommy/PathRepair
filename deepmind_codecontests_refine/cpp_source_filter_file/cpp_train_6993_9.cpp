#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, q;
  cin >> n >> q;
  long long int a[n + 1];
  long long int last[200001];
  long long int first[200001];
  long long int hash[200001] = {};
  memset(last, -1, sizeof(last));
  memset(first, -1, sizeof(first));
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    hash[a[i]]++;
    if (first[a[i]] == -1) first[a[i]] = i;
    last[a[i]] = max(last[a[i]], i);
  }
  long long int i = 1;
  long long int mr = -1;
  long long int ans = 0;
  while (i <= n) {
    mr = max(mr, last[a[i]]);
    long long int freq = 0;
    while (i <= mr) {
      mr = max(mr, last[a[i]]);
      freq = max(freq, hash[a[i]]);
      i++;
    }
    ans += freq;
    i++;
  }
  cout << n - ans;
}
