#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, sumc = 0, summ = 0;
  int a[3], b[3];
  for (i = 0; i < 3; i++) {
    cin >> a[i];
    sumc += a[i];
  }
  for (i = 0; i < 3; i++) {
    cin >> b[i];
    summ += b[i];
  }
  cin >> n;
  int s = 0, t = 0, c = 0;
  t += sumc / 5;
  if (sumc % 5 > 0) t++;
  t += summ / 10;
  if (summ % 10 > 0) t++;
  if (t <= n)
    cout << "YES";
  else
    cout << "NO";
}
