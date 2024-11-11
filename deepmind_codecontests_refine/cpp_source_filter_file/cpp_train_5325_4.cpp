#include <bits/stdc++.h>
using namespace std;
long long a[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long i, j, mi = 1e10;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  long long cnt = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == mi) cnt++;
  }
  if (mi > (n / 2))
    cout << "Bob\n";
  else
    cout << "Alice\n";
  return 0;
}
