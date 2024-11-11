#include <bits/stdc++.h>
using namespace std;
int l[200000];
int m[200000];
int m1[200000];
int m2[200000];
int main() {
  for (int i = 0; i < 200000; i++) {
    l[i] = 0;
    m[i] = 0;
    m1[i] = 0;
    m2[i] = 0;
  }
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) l[i] = 2;
  l[1] = 1;
  l[n] = 1;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    if (m[x - 1] == 1) {
      if (m2[x - 1] == 0) {
        l[x - 1]--;
        m2[x - 1]++;
      }
    }
    if (m[x + 1] == 1) {
      if (m1[x + 1] == 0) {
        l[x + 1]--;
        m1[x + 1]++;
      }
    }
    m[x] = 1;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += l[i];
    if (m[i] == 0) res++;
  }
  if (n == 1)
    cout << 0 << endl;
  else
    cout << res << endl;
}
