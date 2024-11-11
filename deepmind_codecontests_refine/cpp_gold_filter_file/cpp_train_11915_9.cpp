#include <bits/stdc++.h>
using namespace std;
long long row, colomn, matrix[1005][1005], k, p, ro[1000005], co[1000005];
string s;
priority_queue<long long> c, r;
int main() {
  cin >> row >> colomn >> k >> p;
  for (int i = 1; i <= row; i++)
    for (int m = 1; m <= colomn; m++) cin >> matrix[i][m];
  for (int i = 1; i <= row; i++) {
    long long res = 0;
    for (int m = 1; m <= colomn; m++) res += matrix[i][m];
    r.push(res);
  }
  long long ans = -1000000000000000;
  for (int i = 1; i <= colomn; i++) {
    long long res = 0;
    for (int m = 1; m <= row; m++) res += matrix[m][i];
    c.push(res);
  }
  for (int i = 1; i <= k; i++) {
    int top = r.top();
    ro[i] = ro[i - 1] + top;
    r.pop();
    r.push(top - colomn * p);
    top = c.top();
    co[i] = co[i - 1] + top;
    c.pop();
    c.push(top - row * p);
  }
  for (int i = 0; i <= k; i++) {
    long long res = (long long)co[i] + ro[k - i] - p * i * (k - i);
    if (res > ans) ans = res;
  }
  cout << ans;
  return 0;
}
