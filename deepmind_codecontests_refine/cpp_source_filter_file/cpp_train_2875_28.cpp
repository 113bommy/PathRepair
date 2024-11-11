#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k == 0) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  int mid = n / 2;
  if (k == n)
    cout << 0 << " ";
  else
    cout << 1 << " ";
  if (k >= mid) {
    cout << n - k << endl;
  } else
    cout << k + 1 << endl;
  return 0;
}
