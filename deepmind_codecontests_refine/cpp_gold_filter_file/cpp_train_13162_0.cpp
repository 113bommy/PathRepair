#include <bits/stdc++.h>
using namespace std;
int n, s, a[1000000], bank;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    bank += a[i];
  }
  sort(a, a + n);
  if (bank - a[n - 1] <= s)
    cout << "YES";
  else
    cout << "NO";
}
