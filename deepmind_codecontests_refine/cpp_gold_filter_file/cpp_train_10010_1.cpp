#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9 + 7;
const int maxn = 2e5 + 7;
int a[maxn], pos[maxn];
int l[maxn], r[maxn];
int n, res = 0;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  a[0] = a[n + 1] = n + 1;
  vector<int> lf = {0}, rt = {n + 1};
  for (int i = 1; i <= n; i++) {
    while (a[lf.back()] < a[i]) lf.pop_back();
    l[i] = lf.back() + 1;
    lf.push_back(i);
  }
  for (int i = n; i >= 1; i--) {
    while (a[rt.back()] < a[i]) rt.pop_back();
    r[i] = rt.back() - 1;
    rt.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (i - l[i] < r[i] - i) {
      for (int j = l[i]; j < i; j++) {
        int need = a[i] - a[j];
        if (pos[need] >= i && pos[need] <= r[i]) {
          res++;
        }
      }
    } else {
      for (int j = i + 1; j <= r[i]; j++) {
        int need = a[i] - a[j];
        if (pos[need] <= i && pos[need] >= l[i]) {
          res++;
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
