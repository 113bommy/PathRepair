#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, k, pg, pt, flag = 0;
  cin >> n >> k;
  char s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == 'G')
      pg = i;
    else if (s[i] == 'T')
      pt = i;
  }
  if (pg > pt) {
    int t = pg;
    pg = pt;
    pt = t;
  }
  for (int i = pg + k; i < n && s[i] != '#'; i += k) {
    if (s[i] == 'T') {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
