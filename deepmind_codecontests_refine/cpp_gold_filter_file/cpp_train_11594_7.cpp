#include <bits/stdc++.h>
using namespace std;
int s, k, i;
long long f[45];
vector<int> sum;
int main() {
  cin >> s >> k;
  f[1] = 1;
  f[2] = 1;
  int subt;
  for (i = 3; i < 45; ++i) {
    if (i - k - 1 > 0)
      subt = f[i - k - 1];
    else
      subt = 0;
    f[i] = f[i - 1] * 2 - subt;
    if (f[i] > s) {
      --i;
      break;
    }
  }
  for (int j = i; j > 1; --j) {
    if (s - f[j] >= 0) {
      sum.push_back(f[j]);
      s -= f[j];
    }
  }
  if (sum.size() == 1)
    cout << 2 << endl << sum[0] << " 0";
  else {
    cout << sum.size() << endl;
    for (int j = 0; j < sum.size(); ++j) cout << sum[j] << " ";
  }
  return 0;
}
