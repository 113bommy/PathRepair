#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 100005;
long long m = 0;
int mm = 2000000000;
int a[maxn];
bool isodd[maxn] = {false};
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2) {
      isodd[i] = true;
      if (a[i] < mm) mm = a[i];
    }
  }
  for (int i = 1; i <= n; i++) m += a[i];
  if (m % 2) m -= mm;
  cout << m;
  return 0;
}
