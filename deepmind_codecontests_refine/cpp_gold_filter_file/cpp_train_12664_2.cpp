#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int l = 0;
  int q;
  cin >> q;
  vector<int> df;
  long long sumi = 0;
  double maxi = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      df.push_back(x);
      if (df.size() == 1) {
        sumi += x;
        l++;
        continue;
      }
      while (1.0 * (sumi + x) / (l + 1) - df[l] > 1e-9 && l < df.size() - 1)
        sumi += df[l++];
      if (x - (1.0 * (sumi + x) / (l + 1)) - maxi > 1e-9)
        maxi = x - (1.0 * (sumi + x) / (l + 1));
    } else
      printf("%.17lf\n", maxi);
  }
}
