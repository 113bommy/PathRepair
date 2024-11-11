#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  vector<int> ans;
  cin >> t;
  long long *fac = new long long[5000001]();
  long long *m = new long long[5000001]();
  for (int i = 2; i <= 5000000; i++) {
    if (fac[i] == 0)
      for (int j = i; j <= 5000000; j += i) fac[j] = i;
  }
  for (int i = 2; i <= 5000000; i++) {
    int k = i;
    while (k != 1) {
      m[i]++;
      k /= fac[k];
    }
    m[i] += m[i - 1];
  }
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    ans.push_back(m[a] - m[b]);
  }
  for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << endl;
  return 0;
}
