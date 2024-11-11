#include <bits/stdc++.h>
using namespace std;
vector<int> mx;
int comp(int n, int x) {
  int pos = 0;
  int cnt = 0;
  while (1) {
    int a_busq = pos + x;
    cnt++;
    int found = upper_bound(mx.begin(), mx.end(), a_busq) - mx.begin();
    if (found == mx.size()) break;
    found--;
    int estoy = mx[found];
    if (estoy == pos) return (n + 1);
    pos = estoy;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  cin.ignore();
  string second;
  getline(cin, second);
  int n = second.size();
  second = " " + second;
  mx.push_back(0);
  for (int i = 1; i <= n; i++) {
    if (second[i] == ' ' or second[i] == '-') mx.push_back(i);
  }
  mx.push_back(n);
  int l = 1, r = 20000010, mid;
  int ans = r;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (comp(k, mid) <= k)
      r = mid, ans = min(ans, r);
    else
      l = mid;
  }
  cout << ans << '\n';
}
