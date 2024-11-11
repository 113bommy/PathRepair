#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  long long int t;
  t = 1;
  while (t--) {
    long long int n, i, k, t, count[101] = {0};
    cin >> n;
    int z = n;
    while (n--) {
      cin >> t;
      while (t--) {
        cin >> k;
        count[k]++;
      }
    }
    for (i = 0; i <= 10; i++) {
      if (count[i] == z) cout << i << " ";
    }
  }
  return 0;
}
