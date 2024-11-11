#include <bits/stdc++.h>
using namespace std;
int ar[1000], l, r, n, perm[1000];
bool calc() {
  int num = 1;
  l = -1;
  for (int i = 0; i < n; ++i) {
    if (ar[i] != num) {
      l = i;
      break;
    }
    ++num;
  }
  if (l == -1) {
    r = -1;
    return false;
  }
  num = ar[l], r = n - 1;
  for (int i = l; i < n; ++i) {
    if (ar[i] != num) {
      r = i - 1;
      break;
    }
    --num;
  }
  for (int i = l; i < r + 1; ++i)
    if (i + 1 != ar[r - i + l]) {
      l = -1;
      r = -1;
      return false;
    }
  for (int i = r + 1; i < n; ++i)
    if (i + 1 != ar[i]) {
      l = -1;
      r = -1;
      return false;
    }
  return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> ar[i];
  calc();
  cout << l + 1 << " " << r + 1 << endl;
}
