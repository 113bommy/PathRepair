#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1007;
long long qsum(int i, int j, int k) {
  cout << 1 << ' ' << i << ' ' << j << ' ' << k << endl;
  long long ans;
  cin >> ans;
  return ans;
}
int qcross(int i, int j, int k) {
  cout << 2 << ' ' << i << ' ' << j << ' ' << k << endl;
  int ans;
  cin >> ans;
  return ans;
}
long long sum[MAXN];
int cross[MAXN];
int id[MAXN];
inline bool cmp(int a, int b) {
  if (cross[a] != cross[b]) return cross[a] < cross[b];
  if (cross[a] > 0) {
    return sum[a] > sum[b];
  } else {
    return sum[a] < sum[b];
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a = 1, b = 2, c = -1;
  for (int i = 3; i <= n; i++) {
    if (qcross(a, b, i) > 0) {
      b = i;
    }
  }
  sum[a] = sum[b] = 0;
  long long mx = -1;
  for (int i = 2; i <= n; i++)
    if (i != b) {
      sum[i] = qsum(a, b, i);
      if (sum[i] > mx) c = i, mx = sum[i];
    }
  cross[a] = -3;
  cross[b] = 1;
  cross[c] = -1;
  for (int i = 2; i <= n; i++)
    if (i != b && i != c) {
      cross[i] = qcross(a, c, i);
    }
  for (int i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  cout << "0 ";
  for (int i = 1; i <= n; i++) {
    cout << id[i] << " \n"[i == n];
  }
}
