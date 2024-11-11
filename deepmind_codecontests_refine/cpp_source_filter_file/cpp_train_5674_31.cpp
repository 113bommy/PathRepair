#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int main() {
  for (int i = 0; i < 101; i++) a[i] = b[i] = 0;
  int m, n, sp;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    long long mx = 0;
    for (int j = 1; j <= m; j++) {
      long long vot;
      cin >> vot;
      if (vot > mx) {
        mx = vot;
        sp = j;
      }
    }
    a[i] = sp;
  }
  for (int i = 1; i <= n; i++) b[a[i]]++;
  int mx = 0, otv = 0;
  for (int i = 1; i <= m; i++) {
    if (b[i] > mx) {
      mx = b[i];
      otv = i;
    }
  }
  cout << otv;
  return 0;
}
