#include <bits/stdc++.h>
using namespace std;
int getd(int x) {
  if (x < 10) return x;
  return getd(x / 10 + x % 10);
}
int n, dcnt[10];
long long ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= 9; i++) dcnt[i] = n / 9;
  for (int i = 1; i <= n % 9; i++) dcnt[i]++;
  for (int i = 1; i <= 9; i++)
    for (int j = 1; j <= 9; j++) ans += dcnt[i] * dcnt[j] * dcnt[getd(i * j)];
  for (int i = 1; i <= n; i++) ans -= n / i;
  cout << ans << endl;
  return 0;
}
