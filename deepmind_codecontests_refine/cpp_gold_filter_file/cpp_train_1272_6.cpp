#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ans = 0;
struct node {
  long long biao, val;
  int sl;
} b[35];
long long mi = -1;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 31; j >= 0; j--) {
      if ((a[i] >> j) & 1) {
        b[j + 1].sl++;
        if (b[j + 1].sl == 1)
          b[j + 1].val = a[i];
        else
          b[j + 1].val = 0;
      }
    }
  }
  for (int i = 31; i >= 0; i--) {
    if (b[i].val != 0) {
      mi = b[i].val;
      break;
    }
  }
  if (mi != -1) cout << mi << " ";
  for (int i = 1; i <= n; i++)
    if (a[i] != mi) cout << a[i] << " ";
  cout << endl;
}
