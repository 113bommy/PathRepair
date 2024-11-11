#include <bits/stdc++.h>
using namespace std;
long long getPower(int a, int b) {
  long long ans = 1;
  for (int i = 1; i <= b; i++) ans *= a;
  return ans;
}
int main() {
  long long n;
  cin >> n;
  long long check = 10;
  int val = 1;
  while (n >= check) {
    check *= 10;
    val++;
  }
  long long temp = getPower(10, val - 1) - 1;
  temp = n - temp;
  temp = temp * val;
  long long ans = temp;
  for (int i = 1; i < val; i++) ans += i * 9 * getPower(10, i - 1);
  cout << ans;
  return 0;
}
