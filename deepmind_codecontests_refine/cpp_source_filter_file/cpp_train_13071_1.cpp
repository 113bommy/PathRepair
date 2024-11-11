#include <bits/stdc++.h>
using namespace std;
const int bval = 200010;
int k[bval];
int mypow[bval];
int n;
int getnum(int a, int b) {
  b = min(b, 200000);
  return k[b] - k[a - 1];
}
int main() {
  cin >> n;
  fill(k, k + bval, 0);
  for (int i = 0; i < n; i++) {
    cin >> mypow[i];
    k[mypow[i]]++;
  }
  for (int i = 0; i <= 200000; i++) {
    k[i] = k[i] + k[i - 1];
  }
  sort(mypow, mypow + n);
  long long maxmypow = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    int x = mypow[i];
    if (x == prev) continue;
    int j = 1;
    long long curmypow = 0;
    while (j * x <= 200000) {
      curmypow += x * 1L * j * getnum(x * j, x * (j + 1) - 1);
      j++;
    }
    maxmypow = max(maxmypow, curmypow);
    prev = x;
  }
  cout << maxmypow << endl;
  return 0;
}
