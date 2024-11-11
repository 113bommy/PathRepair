#include <bits/stdc++.h>
using namespace std;
int sum(int n) { return (n * (n + 1)) / 2; }
int fibonacci(int n) {
  if (n == 1 || n == 2) {
    return 1;
  }
  return fibonacci((n - 1)) + fibonacci((n - 2));
}
long long nC2(long long n) { return (n * (n - 1)) / 2; }
int removezero(int x) {
  if (x < 10)
    return x;
  else if (x % 10 == 0)
    return removezero(x / 10);
  else
    return removezero(x / 10) * 10 + x % 10;
}
long long cum_1[100005], arr[100005], cum_2[100005];
void Cumulative_Sum(long long arr[], long long n) {
  for (size_t i = 1; i <= n; i++) {
    cum_1[i] = cum_1[i - 1] + arr[i];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, sum = 0, sumi = 0;
  bool flag = false;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a > 1) {
      sum += i * (a - 1) + 1;
    } else {
      sum += a;
    }
  }
  cout << sum << endl;
}
