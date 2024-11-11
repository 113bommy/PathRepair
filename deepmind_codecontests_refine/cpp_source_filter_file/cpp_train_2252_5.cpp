#include <bits/stdc++.h>
using namespace std;
int ar[2000007];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, nsq = 0;
  int art, nz = 0;
  vector<int> diff;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    art = (int)sqrt(ar[i]);
    if (art * art == ar[i])
      nsq++;
    else
      diff.push_back(min(ar[i] - art * art, (art + 1) * (art + 1) - ar[i]));
    if (ar[i] == 0) nz++;
  }
  if (nsq == n / 2)
    cout << 0 << endl;
  else if (nsq > n / 2) {
    int ans = nsq - n / 2;
    if (nz > n / 2) ans += (nz - n / 2);
    cout << ans << endl;
  } else {
    int ans = 0;
    sort(diff.begin(), diff.end());
    for (int i = 0; i < (n / 2 - nsq); i++) ans += diff[i];
    cout << ans << endl;
  }
  return 0;
}
