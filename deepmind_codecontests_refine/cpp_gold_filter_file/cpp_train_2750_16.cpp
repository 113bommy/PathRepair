#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a;
  int count, maks, m;
  int t[1001];
  memset(t, 0, sizeof(t));
  maks = 0;
  count = 0;
  m = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    t[a]++;
    if (a > maks) maks = a;
  }
  for (i = 1; i <= maks; i++) {
    if (t[i] > 0) count++;
    if (t[i] > m) m = t[i];
  }
  cout << m << " " << count << endl;
}
