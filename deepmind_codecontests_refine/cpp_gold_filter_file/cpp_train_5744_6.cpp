#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1);
const int Max = 50010;
const int maxn = 1e5 + 10;
int NumberOfThree(int arr[], int low, int high);
void redirect() {}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
vector<int> vc;
int calc(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
void init() {
  for (int i = 1; i <= 2000; i++)
    if (calc(i) % 4 == 0) vc.push_back(i);
}
int main() {
  redirect();
  init();
  int n = read();
  printf("%d\n", *lower_bound(vc.begin(), vc.end(), n));
  return 0;
}
