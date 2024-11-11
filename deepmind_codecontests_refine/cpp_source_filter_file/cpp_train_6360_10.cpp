#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, n11 = 0, n01 = 0, n00 = 0, n10 = 0;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0' && b[i] == '0')
      n00++;
    else if (a[i] == '1' && b[i] == '0')
      n10++;
    else if (a[i] == '0' && b[i] == '1')
      n01++;
    else if (a[i] == '1' && b[i] == '1')
      n11++;
  }
  cout << (n00 * n11) + (n10 * (n01 + n00));
  return 0;
}
