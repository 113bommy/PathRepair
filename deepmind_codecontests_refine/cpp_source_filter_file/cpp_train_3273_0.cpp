#include <bits/stdc++.h>
using namespace std;
long long h[100005], a[100005], home[100005], away[100005], tmp;
int main() {
  int n, i;
  map<long long, long long> mp;
  while (cin >> n) {
    mp.clear();
    for (i = 0; i < n; i++) {
      cin >> h[i] >> a[i];
      home[i] = (n * (n - 1)) / n;
      away[i] = 0;
      mp[h[i]]++;
    }
    for (i = 0; i < n; i++) {
      tmp = mp[a[i]];
      home[i] += tmp;
      away[i] += (n - tmp) - 1;
      cout << home[i] << " " << away[i] << "\n";
    }
  }
  return 0;
}
