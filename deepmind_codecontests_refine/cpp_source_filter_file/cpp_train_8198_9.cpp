#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[2 * n + 1];
  for (int i = 1; i <= 2 * n; i++) cin >> a[i];
  long long p = 0;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      if (a[i] == a[j] && i != i + 1) {
        for (int k = j; k > i + 1; k--) {
          swap(a[k], a[k - 1]);
          p++;
        }
      }
    }
  }
  cout << p;
  return 0;
}
