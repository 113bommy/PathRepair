#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int kng[n];
  for (int i = 0; i < n; i++) cin >> kng[i];
  sort(kng, kng + n);
  int i = (n - 1) / 2, j = n - 1;
  while (i >= 0) {
    if (kng[j] >= (2 * kng[i]))
      n--, i--, j--;
    else
      i--;
  }
  cout << n;
}
