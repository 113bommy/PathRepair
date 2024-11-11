#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, A, B, first;
  cin >> n >> A >> B;
  cin >> first;
  int sum = first;
  vector<int> a(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  int ans = 0;
  while (1.0 * first * A / sum < B) {
    sum = sum - a[ans];
    ans++;
  }
  if (A == B)
    cout << n - 1;
  else if (n == 1)
    cout << 0;
  else
    cout << ans << endl;
  return 0;
}
