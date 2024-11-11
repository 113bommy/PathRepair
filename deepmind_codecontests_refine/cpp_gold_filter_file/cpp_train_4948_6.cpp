#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 22;
int n, a[MAXN], b[MAXN], r, t;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  for (int i = (1); i <= (n); i++) cin >> b[i];
  if (a[1] == 0) swap(a[1], a[2]);
  if (b[1] == 0) swap(b[1], b[2]);
  for (int i = (1); i <= (n); i++) {
    if (a[i] == 1) t = i;
    if (b[i] == 1) r = i;
  }
  for (int i = (1); i <= (n - 1); i++) {
    if (a[t] != b[r]) return cout << "NO", 0;
    t++, r++;
    if (a[t] == 0) t++;
    if (b[r] == 0) r++;
    if (n < t) t = 1;
    if (n < r) r = 1;
  }
  cout << "YES";
  return 0;
}
