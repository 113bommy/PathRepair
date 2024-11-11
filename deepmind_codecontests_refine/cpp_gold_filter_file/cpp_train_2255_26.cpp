#include <bits/stdc++.h>
using namespace std;
;
int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  long long sum[200010], next = 0;
  vector<long long> idx;
  for (int i = 1; i <= n; i++) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
    idx.push_back(sum[i]);
  }
  for (int i = 1; i <= k; i++) {
    long long res;
    cin >> res;
    next += res;
    if (next >= sum[n]) next = 0;
    int l = upper_bound(idx.begin(), idx.end(), next) - idx.begin();
    cout << idx.size() - l << endl;
  }
}
