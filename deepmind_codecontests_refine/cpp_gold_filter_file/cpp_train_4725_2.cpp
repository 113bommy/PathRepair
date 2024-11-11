#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  if (k > n || k == 1 && n != 1) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < min(n, n - k + 2); i++)
    if (i % 2 == 0)
      cout << "a";
    else
      cout << "b";
  char c = 'c';
  for (int i = 0; i < k - 2; i++) {
    cout << c;
    c++;
  }
}
