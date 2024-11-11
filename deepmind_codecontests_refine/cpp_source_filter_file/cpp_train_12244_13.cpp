#include <bits/stdc++.h>
using namespace std;
char a[105];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, maxi = 0;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    a[i] = s[i];
  }
  sort(a, a + n);
  int t = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1])
      t++;
    else {
      maxi = max(maxi, t);
      t = 1;
    }
  }
  if (maxi > k)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
