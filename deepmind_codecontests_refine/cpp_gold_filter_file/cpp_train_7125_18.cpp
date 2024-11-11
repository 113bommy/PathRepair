#include <bits/stdc++.h>
using namespace std;
long long exp(long long taban, long long us) {
  if (us < 0) return 0;
  long long carpan = taban % 1000000007;
  long long temp = us;
  long long res = 1;
  while (temp) {
    if (temp % 2) res = (res * carpan) % 1000000007;
    temp /= 2;
    carpan = (carpan * carpan) % 1000000007;
  }
  return res;
}
long long ebob(long long a, long long b) {
  if (!a) return b;
  return ebob(b % a, a);
}
long long ekok(long long a, long long b) { return (a * b) / ebob(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &x : vec) cin >> x;
  int ptr1 = -1, ptr2 = -1;
  bool check = 1;
  vec.push_back(0);
  vector<pair<int, int>> segs;
  int basla = 0, bitir = 0;
  for (int i = 0; i < n; i++) {
    if (vec[i] < vec[i + 1]) {
      bitir++;
    } else {
      segs.push_back({basla, bitir});
      basla = i + 1;
      bitir = i + 1;
    }
  }
  int ans;
  ans = segs[0].second - segs[0].first + 1;
  for (int i = 0; i < segs.size() - 1; i++) {
    pair<int, int> ilk = segs[i], iki = segs[i + 1];
    if (ilk.first || ilk.second < n) ans = max(ans, ilk.second - ilk.first + 2);
    if (iki.first || iki.second < n) ans = max(ans, iki.second - iki.first + 2);
    if (ilk.first == ilk.second || iki.first == iki.second) {
      ans = max(ans, iki.second - ilk.first + 1);
      continue;
    }
    if ((iki.first + 1 < n && vec[ilk.second] + 1 < vec[iki.first + 1]) ||
        (ilk.second && vec[iki.first] - 1 > vec[ilk.second - 1])) {
      ans = max(ans, iki.second - ilk.first + 1);
    }
  }
  cout << ans << endl;
}
