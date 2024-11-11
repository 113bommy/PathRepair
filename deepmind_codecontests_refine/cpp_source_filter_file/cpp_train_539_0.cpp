#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  char a[n][l];
  int done[n];
  memset(done, 0, sizeof(done));
  memset(a, 0, sizeof(a));
  int kth = k - 1, strt = 0, curr = 0;
  while (curr < n * l) {
    if (done[0] >= l) break;
    bool f = 0;
    for (int i = strt; i < k - 1; i++) {
      if (!f && s[curr] == s[kth]) {
        strt = i;
        f = 1;
      }
      a[i][done[i]] = s[curr];
      done[i]++;
      curr++;
    }
    a[k - 1][done[k - 1]] = s[kth];
    done[k - 1]++;
    curr++;
    if (!f) {
      break;
    } else {
      curr = kth + 1;
      kth += k - strt;
    }
  }
  while (done[k - 1] < l) {
    a[k - 1][done[k - 1]] = s[curr];
    curr++;
    done[k - 1]++;
  }
  for (int i = 0; i < n; i++) {
    while (done[i] < l) {
      a[i][done[i]] = s[curr];
      curr++;
      done[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
