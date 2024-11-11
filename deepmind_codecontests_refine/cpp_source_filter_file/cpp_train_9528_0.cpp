#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int block_size = 360;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const int inf = 100000000;
const int maxn = 100010;
long long shuzu[10];
long long choose(int a, int b) {
  if (a < b) {
    return 0;
  }
  long long top = 1;
  long long bottom = 1;
  for (long long i = 2; i < b + 1; i++) {
    bottom *= b;
  }
  for (long long i = a; i >= a - b + 1; i--) {
    top *= i;
  }
  return top / bottom;
}
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    cout << 1;
    return 0;
  }
  long long ans_a = 0;
  long long ans_b = 0;
  for (long long i = 1; i < min(n, 5) + 1; i++) {
    long long ways = choose(4, i - 1);
    ways *= choose(n, i);
    ans_a += ways;
  }
  for (long long i = 1; i < min(n, 3) + 1; i++) {
    long long ways = choose(2, i - 1);
    ways *= choose(n, i);
    ans_b += ways;
  }
  cout << ans_a * ans_b << endl;
  return 0;
}
