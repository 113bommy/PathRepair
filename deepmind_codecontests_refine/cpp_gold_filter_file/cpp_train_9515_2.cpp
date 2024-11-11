#include <bits/stdc++.h>
using namespace std;
int i, j, k;
int a[106];
int main() {
  int n;
  cin >> n;
  for ((i) = 0; (i) < (int)(n); (i)++) cin >> a[i];
  int ret = 0;
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      int num = 0;
      for (k = 0; k < n; k++) {
        if ((k < i || k > j) && a[k])
          num++;
        else if (k >= i && k <= j && !a[k])
          num++;
      }
      ret = max(ret, num);
    }
  }
  cout << ret << endl;
}
