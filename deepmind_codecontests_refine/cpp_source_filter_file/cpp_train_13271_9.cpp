#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t = 1;
  vector<long long int> a(31);
  a[0] = 1;
  for (long long int i = 1; i < 31; i++) a[i] = a[i - 1] * 2;
  while (t--) {
    long long int h, w;
    cin >> h >> w;
    long long int j = 0;
    while (a[j] <= h && a[j] <= w) j++;
    long long int h1 = min(h, (long long int)(1.25 * a[j - 1]));
    long long int w1 = min(w, (long long int)(1.25 * a[j - 1]));
    if (h >= w)
      cout << h1 << " " << a[j - 1];
    else
      cout << a[j - 1] << " " << w1;
  }
  return 0;
}
