#include <bits/stdc++.h>
using namespace std;
long long a[10000007];
int main() {
  int t;
  cin >> t;
  long long tmp = 3;
  a[1] = 1;
  for (int i = 2; i < 10000007; i++) {
    a[i] = a[i - 1] + tmp;
    tmp += 2;
  }
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (a[k] <= n && ((n % 2 == 0 && k % 2 == 0) || (n % 2 == 1 && k % 2 == 1)))
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}
