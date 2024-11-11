#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
long long a[maxn][3], s;
int n;
int ans[100];
long long flag;
unsigned long long k = 0;
unsigned long long f = 1;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    for (int j = 61; j >= 0; j--) {
      if (a[i][1] & (f << j)) {
        a[i][2] = j;
        break;
      }
    }
    s += a[i][0];
  }
  if (s > 0)
    s = 1;
  else
    s = -1;
  for (int j = 0; j < 62; j++) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][2] == j) sum += a[i][0];
    }
    if (sum * s > 0) {
      ans[j] = 1;
      for (int i = 0; i < n; i++) {
        if (a[i][1] & (f << j)) a[i][0] = -a[i][0];
      }
    }
  }
  for (int i = 0; i < 62; i++) {
    if (ans[i] > 0) k += (f << i);
  }
  cout << k << endl;
}
