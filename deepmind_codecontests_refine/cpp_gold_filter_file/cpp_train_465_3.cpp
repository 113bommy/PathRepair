#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  multiset<int> S;
  multiset<int>::iterator it;
  vector<int> ans;
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> m;
      S.insert(m);
    }
  }
  int val;
  for (int i = 1; i <= n; i++) {
    it = S.end();
    it--;
    val = *it;
    ans.push_back(val);
    for (int j = 0; j < ans.size(); j++) {
      int r = gcd(ans[j], val);
      S.erase(S.find(r));
      if (j + 1 < ans.size()) S.erase(S.find(r));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << " ";
    cout << ans[i - 1];
  }
  cout << endl;
  return 0;
}
