#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int x;
    cin >> x;
    for (int c = 0; c < x; c++) cin >> a[c];
    map<int, int> Q;
    for (int j = 0; j < x; j++) Q[a[j]]++;
    map<int, int>::iterator iter;
    map<int, int> W;
    for (iter = Q.begin(); iter != Q.end(); iter++) {
      W[iter->second]++;
    }
    map<int, int>::reverse_iterator zz;
    zz = W.rbegin();
    int f = zz->first;
    int s = zz->second;
    long long sum = 0;
    for (; zz != W.rend();) {
      zz++;
      if (zz == W.rend()) {
        long long hh = min(f, s);
        sum = sum + (f + f - hh + 1) * hh / 2;
      } else if (f - (zz->first) <= s) {
        sum = sum + (f + zz->first + 1) * (f - (zz->first)) / 2;
        zz->second = zz->second + s - (f - (zz->first));
      } else
        sum = sum + (f * 2 - s + 1) * s / 2;
      f = zz->first;
      s = zz->second;
    }
    cout << sum << endl;
  }
  return 0;
}
