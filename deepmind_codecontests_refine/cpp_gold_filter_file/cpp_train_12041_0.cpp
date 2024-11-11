#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
int spf[MAXN];
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < MAXN; i++) spf[i] = i;
  for (int i = 4; i < MAXN; i += 2) spf[i] = 2;
  for (int i = 3; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < MAXN; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    if (n < 6) {
      cout << -1 << endl;
      for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << endl;
      }
    } else {
      cout << 1 << " " << 2 << endl;
      cout << 1 << " " << 3 << endl;
      cout << 1 << " " << 4 << endl;
      for (int i = 5; i <= n; i++) {
        cout << 2 << " " << i << endl;
      }
      for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << endl;
      }
    }
  }
}
