#include <bits/stdc++.h>
using namespace std;
const int MX = 205;
int n, a[MX], res = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  n *= 2;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i += 2) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        j--;
        while (j > i) {
          swap(a[j], a[j + 1]);
          res++;
          j--;
        }
        break;
      }
    }
  }
  cout << res << '\n';
  return 0;
}
