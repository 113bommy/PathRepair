#include <bits/stdc++.h>
using namespace std;
map<pair<string, string>, int> p;
int ans[305];
int main() {
  ios_base::sync_with_stdio(0);
  int n, a, b, k, f, Ans = 0;
  string R, l, r;
  cin >> n >> a >> b >> k >> f;
  cin >> l >> R;
  p[{min(l, R), max(l, R)}] = a;
  for (int i = 1; i < n; i++) {
    cin >> l >> r;
    if (l == R) {
      p[{min(l, r), max(l, r)}] += b;
    } else {
      p[{min(l, r), max(l, r)}] += a;
    }
    R = r;
  }
  int j = 0;
  for (auto i : p) {
    ans[j++] = i.second;
  }
  sort(ans, ans + j);
  for (int i = j - 1; i >= 0; i--) {
    if (k > 0 && f < ans[i]) {
      Ans += f;
      k--;
    } else {
      Ans += ans[i];
    }
  }
  cout << Ans;
  return 0;
}
