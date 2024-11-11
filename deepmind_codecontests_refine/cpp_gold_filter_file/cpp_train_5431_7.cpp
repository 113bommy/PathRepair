#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int inf = 0x3f3f3f3f;
const int finf = -0x3f3f3f3f - 1;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n;
double a[maxn];
int b[maxn];
bool f[maxn];
int cha;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = int(a[i]);
    if (a[i] == b[i]) f[i] = true;
    cha += b[i];
  }
  if (cha < 0) {
    for (int i = 1; i <= n && cha != 0; i++) {
      if (a[i] > 0 && !f[i]) b[i]++, cha++;
    }
  } else {
    for (int i = 1; i <= n && cha != 0; i++) {
      if (a[i] < 0 && !f[i]) b[i]--, cha--;
    }
  }
  for (int i = 1; i <= n; i++) cout << b[i] << endl;
  return 0;
}
