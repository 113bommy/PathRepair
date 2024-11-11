#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int go(int p) { return pow(2, p); }
int main() {
  int n;
  cin >> n;
  vector<int> ans;
  int p = 1;
  while (n) {
    if (n % 2) ans.push_back(p);
    n /= 2;
    p++;
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
