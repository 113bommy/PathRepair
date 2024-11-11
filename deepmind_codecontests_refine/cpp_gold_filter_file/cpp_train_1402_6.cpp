#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l, r;
  cin >> l >> r;
  l++;
  l += !(l % 2);
  if (l + 1 > r)
    cout << "-1";
  else
    cout << l - 1 << " " << l << " " << l + 1;
}
