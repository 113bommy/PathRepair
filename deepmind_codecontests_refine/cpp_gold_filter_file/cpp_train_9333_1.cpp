#include <bits/stdc++.h>
using namespace std;
long long x, d, dem = 0, kq[10001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> x >> d;
  long long t = 1, sl = 0;
  for (int i = 60; i >= 1; i--)
    if (((x >> i) & 1) != 0) {
      for (int j = 1; j <= i; j++) kq[++dem] = t;
      sl++;
      t += d + 1;
    }
  while (sl) {
    t += d + 1;
    kq[++dem] = t;
    sl--;
  }
  if (x % 2 == 1) kq[++dem] = t + d + 1;
  cout << dem << "\n";
  for (int i = 1; i <= dem; i++) cout << kq[i] << " ";
}
