#include <bits/stdc++.h>
using namespace std;
int A[200000];
int idx[10000];
int len[10000];
int main() {
  int l, b, f;
  cin >> l >> b >> f;
  int n;
  cin >> n;
  memset(A, 0, sizeof(A));
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> len[i];
      int res = -1;
      int cl = 0;
      for (int j = 0; j <= l + b; j++) {
        if (A[j] == 0) cl++;
        if (A[j] == 1) cl = 0;
        if (cl == len[i] + f && j + 1 == cl) {
          res = 0;
          break;
        }
        if (cl == len[i] + f + b) {
          res = j - len[i] - f + 1;
          break;
        }
      }
      if (res >= l) res = -1;
      if (res + len[i] > l) res = -1;
      if (res == -1)
        cout << res << endl;
      else {
        idx[i] = res;
        cout << res << endl;
        for (int j = res; j < res + len[i]; j++) A[j] = 1;
      }
    } else {
      int i;
      cin >> i;
      i--;
      for (int j = idx[i]; j < idx[i] + len[i]; j++) A[j] = 0;
    }
  }
  return 0;
}
