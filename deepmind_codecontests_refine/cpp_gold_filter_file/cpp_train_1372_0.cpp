#include <bits/stdc++.h>
using namespace std;
long long int exp(long long int a, long long int b, long long int m);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int q;
  cin >> q;
  long long int n1 = n;
  n = q;
  long long int ind = -1;
  long long int aq[q][3];
  for (long long int i = 0; i < n; i++) {
    cin >> aq[i][0];
    cin >> aq[i][1];
    if (aq[i][0] == 1) {
      cin >> aq[i][2];
    }
  }
  long long int su[n];
  long long int x = 0;
  for (long long int i = 0; i < n; i++) {
    if (aq[n - i - 1][0] == 2) x = max(x, aq[n - i - 1][1]);
    su[n - i - 1] = x;
  }
  for (long long int i = 0; i < n1; i++) a[i] = max(a[i], x);
  for (long long int i = 0; i < n; i++) {
    if (aq[i][0] == 1) {
      a[aq[i][1] - 1] = max(su[i], aq[i][2]);
    }
  }
  for (long long int i = 0; i < n1; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
long long int exp(long long int a, long long int b, long long int m) {
  if (b == 0) {
    return 1;
  }
  long long int temp = exp(a, b / 2, m);
  temp = (temp * temp) % m;
  if (b & 1) {
    return (temp * (a % m)) % m;
  }
  return temp;
}
