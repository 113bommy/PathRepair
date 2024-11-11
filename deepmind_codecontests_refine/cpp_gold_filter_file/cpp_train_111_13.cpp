#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  sort(a + 1, a + 1 + n);
  for (int i = a[n];; i++) {
    int cnt = i * n;
    if (cnt > 2 * sum) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
