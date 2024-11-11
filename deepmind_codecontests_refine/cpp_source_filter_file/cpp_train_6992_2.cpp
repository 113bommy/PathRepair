#include <bits/stdc++.h>
using namespace std;
long long int n, m;
long long int arr[300000];
long long int brr[300000];
long long int fin[300000];
map<long long int, vector<long long int> > ma;
vector<long long int> vec;
set<long long int> se;
long long int getSum(long long int BITree[], long long int index) {
  long long int sum = 0;
  index = index + 1;
  while (index > 0) {
    sum += BITree[index];
    index -= index & (-index);
  }
  return sum;
}
void updateBIT(long long int BITree[], long long int n, long long int index,
               long long int val) {
  index = index + 1;
  while (index <= n) {
    BITree[index] += val;
    index += index & (-index);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int TESTS, q, a, s, b, r, l, k, c, p, h, w, d, x, y, z, xs, ys, t;
  TESTS = 1;
  memset(fin, 0, sizeof(fin));
  while (TESTS--) {
    cin >> n;
    for (long long int i = 0; i <= n - 1; i++) {
      cin >> arr[i] >> brr[i];
      ma[brr[i]].push_back(arr[i]);
    }
    arr[n] = 0;
    sort(arr, arr + n + 1);
    sort(brr, brr + n);
    for (long long int i = 0; i <= n - 1; i++) {
      if (brr[i] == brr[i + 1] && i != n - 1) continue;
      ma[brr[i]].push_back(0);
      sort(ma[brr[i]].begin(), ma[brr[i]].end());
      vec.push_back(brr[i]);
    }
    long long int ans = 0;
    reverse(vec.begin(), vec.end());
    for (auto it : vec) {
      m = ma[it].size();
      for (long long int i = 0; i <= m - 1; i++)
        if (se.find(ma[it][i]) == se.end()) {
          se.insert(ma[it][i]);
          long long int ind = lower_bound(arr, arr + n + 1, ma[it][i]) - arr;
          updateBIT(fin, n + 1, ind, 1);
        }
      for (long long int i = 1; i <= m - 1; i++) {
        long long int ind = lower_bound(arr, arr + n + 1, ma[it][i]) - arr;
        long long int prev = lower_bound(arr, arr + n + 1, ma[it][i - 1]) - arr;
        ans += (getSum(fin, ind) - getSum(fin, prev)) *
               (getSum(fin, n + 1) - getSum(fin, ind - 1));
      }
    }
    cout << ans;
  }
  return 0;
}
