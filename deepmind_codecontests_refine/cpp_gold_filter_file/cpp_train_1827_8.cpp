#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, arr[999], q;
int main() {
  cin >> n >> m;
  while (i++ < 4 * n && m--) {
    arr[i] = ++q;
    i++;
  }
  while (j < 4 * n && m-- > 0) {
    arr[j] = ++q;
    j += 2;
  }
  while (k < 4 * n)
    if (arr[k++]) cout << arr[k - 1] << " ";
}
