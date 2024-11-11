#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double PI = acos(-1.0);
const int MAXN = 100000 + 7;
int a[MAXN];
int n;
long long solve(int l, int r) {
  vector<int> v(r - l);
  for (int i = l + 1; i <= r; i++) {
    v[i - l - 1] = abs(a[i] - a[i - 1]);
  }
  int n = v.size();
  vector<long long> val(n), occ(n), tot(n);
  int it = 1;
  val[0] = v[0];
  occ[0] = 1;
  tot[0] = v[0];
  long long ans = 0;
  ans += tot[0];
  for (int i = 1; i < v.size(); i++) {
    long long new_occ = 1;
    while (it && val[it - 1] < v[i]) {
      it--;
      new_occ += occ[it];
    }
    val[it] = v[i];
    occ[it] = new_occ;
    tot[it] = (it ? tot[it - 1] : 0) + v[i] * new_occ;
    ans += tot[it];
    it++;
  }
  return ans;
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    cout << solve(l, r) << endl;
  }
  return 0;
}
