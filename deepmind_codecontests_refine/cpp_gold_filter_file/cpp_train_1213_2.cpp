#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, A, B;
  cin >> n >> A >> B;
  int a[n - 1];
  int first;
  cin >> first;
  int S = first;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
    S += a[i];
  }
  sort(a, a + n);
  for (int i = n - 2; i >= 0; i--) {
    if ((first * A) / S >= B) {
      cout << ans << endl;
      return 0;
    }
    S -= a[i];
    ans++;
  }
  cout << ans << endl;
  return 0;
}
