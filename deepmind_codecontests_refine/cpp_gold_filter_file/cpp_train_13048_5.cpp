#include <bits/stdc++.h>
using namespace std;
int n, d;
long long int pos, m, l, fim, mod;
bool foi[1000010];
int main() {
  memset(foi, false, sizeof(foi));
  scanf("%d %d %lld %lld", &n, &d, &m, &l);
  pos = d;
  fim = (n - 1) * m + l + 1;
  while (pos < fim) {
    mod = pos % m;
    if (mod > l) break;
    if (foi[mod])
      pos = fim + (fim % d == 0 ? 0 : d - (fim % d));
    else
      pos += d;
    foi[mod] = true;
  }
  cout << pos << "\n";
  return 0;
}
