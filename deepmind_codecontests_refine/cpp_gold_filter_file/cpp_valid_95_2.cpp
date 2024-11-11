#include <bits/stdc++.h>
using namespace std;
int digs(int x) {
  int ans = 0;
  while (x) {
    x /= 10;
    ans++;
  }
  return ans;
}
void test() {
  int s, n;
  cin >> s >> n;
  vector<int> res(n);
  for (int i = n; i > 0; i--) {
    int d = digs(s);
    int cand = pow(10, d - 1);
    while (s - cand < i - 1) cand /= 10;
    if (i == 1) cand = s;
    res[i - 1] = cand;
    s -= cand;
  }
  for (int x : res) cout << x << ' ';
  cout << "" << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    test();
  }
}
