#include <bits/stdc++.h>
using namespace std;
int main() {
  long long num[10];
  num[1] = 11;
  num[0] = 1;
  for (int i = 2; i <= 9; i++) {
    long long sum = 1;
    for (int j = 1; j < i; j++) sum *= 10;
    num[i] = num[i - 1] + i * 9 * sum + 1;
  }
  long n, temp;
  cin >> n;
  int ans = 0;
  temp = n;
  while (temp) {
    temp /= 10;
    ans++;
  }
  long long sum = 1;
  for (int j = 1; j < ans; j++) sum *= 10;
  ans = num[ans - 1] + (n - sum) * ans;
  cout << ans << endl;
}
