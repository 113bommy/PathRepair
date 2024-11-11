#include <bits/stdc++.h>
using namespace std;
int n, k, w[10005];
long long dzep;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    dzep += w[i] / k + (w[i] % k > 0);
  }
  cout << dzep / 2 + dzep % 2 << endl;
  return 0;
}
