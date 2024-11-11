#include <bits/stdc++.h>
using namespace std;
long long cont[1000010];
int main() {
  long long N;
  int x;
  while (cin >> N) {
    memset(cont, 0, sizeof(cont));
    long long ans = 0;
    for (long long i = int(0); i < int(N); i++) {
      scanf("%d", &x);
      cont[x]++;
    }
    for (long long i = int(0); i < int(1000001); i++) {
      cont[i + 1] += cont[i] / 2;
      cont[i] %= 2;
      ans += cont[i];
    }
    if (cont[1000000] % 2 == 0)
      ans += cont[1000000] / 2;
    else
      ans += (cont[1000000] / 2) + 1;
    cout << ans << "\n";
  }
}
