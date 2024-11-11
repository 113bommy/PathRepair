#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1e7 + 10;
long long ans;
bool se[MAXV];
int main() {
  int n, a;
  cin >> n >> a;
  int l = n, r = n + a - 1;
  for (int i = 3200; i >= 1; i--)
    for (int j = i * i; j < MAXV; j += i * i) {
      if (se[j]) continue;
      if (l <= j && j <= r) ans += i * i;
      se[j] = 1;
    }
  cout << ans;
}
