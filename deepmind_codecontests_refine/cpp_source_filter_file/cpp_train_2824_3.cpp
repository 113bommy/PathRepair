#include <bits/stdc++.h>
using namespace std;
long long n, a[1000], k = 1, maxx, q;
string s;
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i + 1]) k++;
    if (a[i] == a[i + 1]) {
      maxx = max(k, maxx);
      k = 1;
    }
  }
  cout << max(maxx, k);
}
