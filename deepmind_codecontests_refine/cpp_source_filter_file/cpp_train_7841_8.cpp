#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e7 + 10;
bool ispr[MAX];
int pr[MAX], pn, n;
void init() {
  memset(ispr, true, sizeof(ispr));
  for (int k = 2; k < MAX; k++) {
    if (ispr[k]) pr[pn++] = k;
    for (int i = 0; i < pn && k * pr[i] < MAX; i++) {
      ispr[k * pr[i]] = false;
      if (k % pr[i] == 0) break;
    }
  }
}
int main() {
  init();
  scanf("%d", &n);
  long long ans = 0;
  int i = 0;
  while (n > 1 && i < pn) {
    while (n % pr[i] == 0) {
      ans += (long long)n / pr[i];
      n /= pr[i];
    }
    i++;
  }
  if (i >= pn) ans = n;
  cout << ans << endl;
  return 0;
}
