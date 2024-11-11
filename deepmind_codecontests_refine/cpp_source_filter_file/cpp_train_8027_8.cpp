#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 6;
int n, k;
long long sum;
long long tab[N];
int wyn[N];
void win() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> tab[i];
    tab[i] += tab[i - 1];
  }
  if (tab[n] % k) {
    cout << "NO" << endl;
    return;
  }
  sum = tab[n] / k;
  for (int i = 1; i <= n; i++) {
    if (!(tab[i] % sum)) {
      wyn[tab[i] / sum] = i;
    }
  }
  for (int i = 1; i <= k; i++) {
    if (!wyn[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= k; i++) cout << wyn[i] - wyn[i - 1] << " ";
  cout << endl;
}
int main() {
  int m = 1;
  while (m--) {
    win();
  }
}
