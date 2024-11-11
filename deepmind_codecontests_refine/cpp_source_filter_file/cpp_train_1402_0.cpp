#include <bits/stdc++.h>
int arr[100000];
using namespace std;
int main() {
  long long l, r;
  cin >> l >> r;
  if (l % 2 != 0) {
    l++;
  }
  if (abs(l - r) == 1) {
    cout << -1 << endl;
    return 0;
  } else
    cout << l << " " << l + 1 << " " << l + 2 << endl;
  return 0;
}
