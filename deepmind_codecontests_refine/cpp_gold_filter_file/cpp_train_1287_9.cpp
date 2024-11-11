#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, x, s = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    s += x;
  }
  if (s % n == 0)
    cout << n;
  else
    cout << n - 1;
}
