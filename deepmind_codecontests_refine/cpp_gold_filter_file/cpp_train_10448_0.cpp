#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int mem[(int)1e6 + 1];
int countDivisors(int n) {
  int &cnt = mem[n];
  if (cnt != -1) {
    cnt = mem[n];
    return cnt;
  }
  cnt = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cnt++;
      else
        cnt = cnt + 2;
    }
  }
  return cnt;
}
int main() {
  cin >> a >> b >> c;
  for (int i = 0; i < (int)1e6 + 1; i++) mem[i] = -1;
  long long sum = 0;
  for (int i = 1; i <= a; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++) {
        mem[i * j * k] = countDivisors(i * j * k);
        sum += mem[i * j * k];
      }
  cout << sum;
  return 0;
}
