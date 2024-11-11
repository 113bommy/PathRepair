#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  long long int n, k, i;
  cin >> n >> k;
  if (k % 2 == 1) {
    i = (k - 1) / 2;
    if (i + 1 <= n && i > 0)
      cout << min(i, (n - i));
    else
      cout << "0";
  } else {
    i = (k - 2) / 2;
    if (i + 2 <= n && i > 0)
      cout << min((n - i - 1), i);
    else
      cout << "0";
  }
  return 0;
}
