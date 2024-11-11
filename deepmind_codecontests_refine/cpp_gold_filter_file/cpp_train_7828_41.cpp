#include <bits/stdc++.h>
using namespace std;
const long long inf = 10000003;
long long n, m, k = 0, q;
int a[102];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> q;
    a[q]++;
  }
  int cnt = 0;
  for (int i = 0; i <= 100; i++) {
    cnt += a[i] / 2;
  }
  cout << cnt / 2;
  return 0;
}
