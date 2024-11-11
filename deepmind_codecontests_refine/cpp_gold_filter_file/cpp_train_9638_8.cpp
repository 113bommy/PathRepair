#include <bits/stdc++.h>
using namespace std;
int t = 1, n;
vector<int> ar;
void solve() {
  cin >> n;
  char bruh = 'a';
  ar.resize(n);
  for (int i = 0; i < n; i++) cin >> ar[i];
  for (int i = n - 1; i >= 0; i--) {
    if (ar[i] > 0) {
      for (int j = i - 1, k = 2 * ar[i]; j >= 0; j--, k += ar[i]) {
        ar[j] -= k;
      }
    }
    for (int j = 0; j < ar[i]; j++) {
      for (int k = 0; k < i + 1; k++) {
        cout << bruh;
      }
      if (bruh >= 'a' + 25) bruh = 'a';
      bruh++;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (t--) {
    solve();
  }
  return 0;
}
