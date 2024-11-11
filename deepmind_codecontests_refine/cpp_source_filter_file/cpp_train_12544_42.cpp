#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, sq = 1001;
int n, x[maxn], y[maxn], per[maxn];
bool comp(int i, int j) {
  if (x[i] / sq == x[j] / sq) return y[i] < y[j];
  return x[i] < x[j];
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i], per[i] = i;
  sort(per, per + n, comp);
  for (int i = 0; i < n; i++) cout << per[i] + 1 << ' ';
  return 0;
}
