#include <bits/stdc++.h>
using namespace std;
int n, ans, x, j = 0, k = 0, b[3000], a[3000], first[3000], second[3000];
bool check;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= a[i - 1]) k++;
    a[i] = x;
    b[i] = x;
  }
  if (k == n) {
    cout << 0;
    return 0;
  }
  k = 0;
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    if (b[i] != a[i]) {
      while (b[i] != a[j]) j++;
      ans++;
      swap(a[i], a[j]);
      first[k] = i;
      second[k] = j;
      k++;
    }
    j = i + 1;
  }
  cout << ans << endl;
  for (int i = 0; i < ans; i++) cout << first[i] << " " << second[i] << endl;
}
