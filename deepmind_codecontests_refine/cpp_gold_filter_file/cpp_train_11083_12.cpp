#include <bits/stdc++.h>
using namespace std;
vector<int> sTree;
void build(int left, int right, int ind, vector<int> &arr) {
  if (left == right) {
    sTree[ind] = arr[left];
    return;
  }
  int lTree = ind * 2, rTree = lTree + 1;
  int mid = (left + right) / 2;
  build(left, mid, lTree, arr);
  build(mid + 1, right, rTree, arr);
  sTree[ind] = sTree[lTree] & sTree[rTree];
}
long long int query(int left, int right, int L, int R, int ind,
                    vector<int> &arr) {
  if (L >= left && R <= right) return (long long int)sTree[ind];
  if (R < left || L > right) return ((1ll << 31) - 1);
  int mid = (L + R) / 2;
  long long int lVal = query(left, right, L, mid, ind * 2, arr),
                rVal = query(left, right, mid + 1, R, ind * 2 + 1, arr);
  long long int ans = lVal & rVal;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, j;
  cin >> n >> m;
  sTree.resize(4 * n);
  vector<int> l(m), r(m), q(m);
  for (i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    l[i]--;
  }
  vector<int> sum(n + 1), a(n);
  for (i = 0; i < n; i++) {
    a[i] = 0;
  }
  for (int bit = 0; bit <= 30; bit++) {
    for (i = 0; i <= n; i++) {
      sum[i] = 0;
    }
    for (i = 0; i < m; i++) {
      if ((q[i] >> bit) % 2) {
        sum[l[i]]++;
        sum[r[i]]--;
      }
    }
    for (i = 1; i <= n; i++) {
      sum[i] += sum[i - 1];
    }
    for (i = 0; i < n; i++) {
      if (sum[i] > 0) {
        a[i] |= 1 << bit;
      }
    }
  }
  build(0, n - 1, 1, a);
  for (i = 0; i < m; i++) {
    if (query(l[i], r[i] - 1, 0, n - 1, 1, a) != q[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
