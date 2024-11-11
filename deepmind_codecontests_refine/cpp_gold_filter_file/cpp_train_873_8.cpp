#include <bits/stdc++.h>
using namespace std;
bool check(int x, int k) {
  int digitsCounter[10];
  for (int i = 0; i <= 9; i++) digitsCounter[i] = 0;
  while (x > 0) {
    digitsCounter[x % 10]++;
    x /= 10;
  }
  for (int i = 0; i <= k; i++)
    if (digitsCounter[i] == 0) return false;
  return true;
}
int main() {
  int n, k;
  cin >> n >> k;
  int res = 0, tem;
  for (int i = 0; i < n; i++) {
    cin >> tem;
    if (check(tem, k)) res++;
  }
  cout << res;
  return 0;
}
