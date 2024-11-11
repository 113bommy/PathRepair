#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  long long n, i, count = 0;
  cin >> n;
  long long a[2];
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (count == 0) a[count++] = i;
      if (n / i != i && (n / i) % i != 0) count++;
      if (count == 1 && i % a[0] != 0) count++;
    }
    if (count >= 2) break;
  }
  if (count >= 2)
    cout << "1";
  else if (count == 1)
    cout << a[0];
  else
    cout << n;
  return 0;
}
