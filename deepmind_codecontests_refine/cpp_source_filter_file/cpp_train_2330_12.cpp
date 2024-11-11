#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int i = 0; i < (n); i++) cin >> v[i];
  int i = 0, j = 1, tt = v[0], re = 1;
  while (i < ((int)(v).size()) && j < ((int)(v).size())) {
    if (tt + v[j] <= t) {
      tt += v[j];
      j++;
    } else {
      tt -= v[i];
      i++;
    }
    re = max(re, j - i);
  }
  cout << re << endl;
  return 0;
}
