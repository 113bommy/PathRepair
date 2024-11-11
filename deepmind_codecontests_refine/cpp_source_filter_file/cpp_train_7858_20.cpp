#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int a[100000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int cnt = 1;
  int maxx = 0;
  for (int i = 1; i < n; i++) {
    while (a[i - 1] <= a[i] && i < n) {
      i++;
      cnt++;
    }
    maxx = max(cnt, maxx);
    cnt = 1;
  }
  cout << maxx << endl;
  return 0;
}
