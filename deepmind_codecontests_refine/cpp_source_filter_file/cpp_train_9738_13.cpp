#include <bits/stdc++.h>
using namespace std;
int n, k, cnta, cntb, j, maxx;
char v[100000];
int main() {
  cin >> n >> k >> v;
  for (int i = 0; i < n; i++) {
    if (v[i] == 'a')
      cnta++;
    else
      cntb++;
    while (abs(cnta - cntb) > k) {
      if (v[j] == 'a')
        cnta--;
      else
        cntb--;
      j++;
    }
    maxx = max(maxx, i - j + 1);
  }
  cout << maxx;
  return 0;
}
