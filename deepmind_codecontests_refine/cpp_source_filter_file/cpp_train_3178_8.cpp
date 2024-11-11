#include <bits/stdc++.h>
using namespace std;
int power(int a, int b) {
  if (b == 0) return a;
  int ans = power(a, b / 2);
  if (b % 2 == 0)
    return ans * ans;
  else
    return ans * ans * a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, b, p;
    scanf("%lld %lld %lld", &n, &b, &p);
    long long int tp = p * n;
    long long int tb = 0;
    long long int num = n;
    int f = 10;
    while (1) {
      if (num == 1) break;
      long long int part = 1;
      while (part * 2LL <= num) {
        part = part * 2LL;
      }
      long long int rest = num - part;
      tb += (part * b + (part / 2));
      num = part / 2;
      num += rest;
    }
    cout << tb << " " << tp << endl;
  }
  return 0;
}
