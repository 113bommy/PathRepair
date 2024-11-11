#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 57LL;
long long expo(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return expo(a * a, b / 2);
  else
    return a * expo(a * a, b / 2);
}
long long hcf(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  return (b == 0) ? a : hcf(b, a % b);
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  int an[n][2];
  bool found = false;
  int summ = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 0) {
      found = true;
    }
    summ += a[i];
  }
  if (!found) {
    cout << "NO";
  } else if (summ != 0) {
    cout << "YES\n1\n1 " << n << '\n';
  } else {
    int i = 0;
    while (a[i] == 0) i++;
    cout << "YES\n2\n1 " << i + 1 << "\n" << i + 2 << " " << n;
  }
  return 0;
}
