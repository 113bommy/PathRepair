#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, i, j, l, last, otv = 0, pro;
  cin >> n >> k >> x;
  int *kol = new int[n];
  int *num = new int[n];
  for (i = 0; i < n; i++) num[i] = 0;
  cin >> l;
  kol[0] = l;
  num[0] = 1;
  i = 0;
  for (j = 1; j < n; j++) {
    cin >> l;
    if (l == kol[i])
      num[i]++;
    else {
      i++;
      num[i] = 1;
      kol[i] = l;
    }
  }
  last = i;
  for (i = 0; i <= last; i++)
    if ((kol[i] == x) && (num[i] == 2)) {
      pro = 2;
      l = i - 1;
      j = i + 1;
      while ((l >= 0) && (j <= last) && (kol[l] == kol[j]) &&
             ((num[l] + num[j]) > 2)) {
        pro = pro + num[l] + num[j];
        l--;
        j++;
      }
      if (pro > otv) otv = pro;
    }
  cout << otv;
  return 0;
}
