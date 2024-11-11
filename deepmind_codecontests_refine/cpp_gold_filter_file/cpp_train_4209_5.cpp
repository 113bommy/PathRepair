#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, cn = 0, o, t;
  cin >> n >> k;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  for (i = 0; i < k; i++) {
    o = t = 0;
    for (j = i; j < n; j += k) {
      if (arr[j] == 1)
        o++;
      else
        t++;
    }
    cn += min(o, t);
  }
  cout << cn << endl;
  return 0;
}
