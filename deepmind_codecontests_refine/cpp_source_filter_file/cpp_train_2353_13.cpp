#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, q;
  cin >> n >> k >> q;
  vector<long long> temperature(200005), pref(200005);
  while (n--) {
    long long l, r;
    cin >> l >> r;
    temperature[l]++;
    temperature[r + 1]--;
  }
  for (int i = 1; i < 200005; i++) temperature[i] += temperature[i - 1];
  for (int i = 1; i < 20005; i++) {
    pref[i] = pref[i - 1];
    if (temperature[i] >= k) pref[i]++;
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << "\n";
  }
}
