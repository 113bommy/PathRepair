#include <bits/stdc++.h>
using namespace std;
long long int a[100005], n, mx = 1, l = 0, p = 0;
bool mto = false;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < n; j++) {
    l = 2;
    mto = false;
    if (j < 2) continue;
    p = j;
    if (a[p] == 1 && a[p - 1] == 1) {
      l = 2;
      p++;
      j++;
      mto = true;
    }
    while ((a[p] == a[p - 1] + a[p - 2]) && p < n) {
      l++;
      mto = true;
      p++;
      j++;
    }
    if (l > mx && mto) mx = l;
    l = 2;
  }
  if (n == 2 || n == 1) l = n;
  cout << mx << endl;
  return 0;
}
