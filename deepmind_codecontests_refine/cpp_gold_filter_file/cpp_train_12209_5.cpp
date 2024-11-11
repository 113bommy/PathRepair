#include <bits/stdc++.h>
using namespace std;
int pow(int base, int exp) {
  int result = 1, n = base;
  while (exp) {
    if (1 & exp) result *= base;
    exp /= 2;
    n *= n;
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    long long T;
    cin >> n >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> c(n);
    long long i, j;
    long long Tby2 = T / 2;
    long long flag = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == T / 2 && T % 2 == 0) {
        c[i] = flag;
        flag = flag == 0 ? 1 : 0;
      } else if (2 * a[i] < T)
        c[i] = 0;
      else
        c[i] = 1;
    }
    for (i = 0; i < n; i++) cout << c[i] << " ";
    cout << "\n";
  }
  return 0;
}
