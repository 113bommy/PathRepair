#include <bits/stdc++.h>
using namespace std;
void Heavy_Gaurav_Singh() {
  vector<long long> c(3);
  for (int i = 0; i < 3; i++) cin >> c[i];
  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    if (*min_element(c.begin(), c.end()) >= i) {
      long long t = i;
      for (auto x : c) t += (x - i) / 3;
      ans = max(ans, t);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) {
    Heavy_Gaurav_Singh();
  }
  return 0;
}
