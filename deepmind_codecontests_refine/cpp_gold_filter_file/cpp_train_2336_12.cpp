#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 + 10, Maxm = 21;
const long long Inf = 1ll << 60;
int n, m, b, x[Maxn], k[Maxn], pro[Maxn];
vector<pair<int, int> > num;
long long d[1048596];
void input() {
  int mi, a;
  scanf("%d%d%d", &n, &m, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &x[i], &k[i], &mi);
    num.push_back(make_pair(k[i], i));
    for (int j = 0; j < mi; j++) {
      cin >> a;
      a--;
      pro[i] += (1 << a);
    }
  }
  sort(num.begin(), num.end());
}
void solve() {
  int all = (1 << m) - 1;
  for (int i = 0; i < all; i++) d[i] = Inf;
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j < all; j++) {
      int name = num[i].second;
      int nw = (j | pro[name]);
      if (nw == all)
        d[j] = min(d[j], (long long)x[name] + (long long)b * k[name]);
      else
        d[j] = min(d[j], (long long)x[name] + d[nw]);
    }
  if (d[0] == Inf) {
    cout << "-1" << endl;
    return;
  }
  printf("%I64d\n", d[0]);
}
int main() {
  input();
  solve();
  return 0;
}
