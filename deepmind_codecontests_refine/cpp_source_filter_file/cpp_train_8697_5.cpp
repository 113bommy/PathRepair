#include <bits/stdc++.h>
using namespace std;
const int EPS = 1e-6;
const int INF = (int)(INT_MAX - 100);
const long long mod = (int)(1e+9 + 7);
const int N = (int)(1e5);
int main() {
  int n;
  cin >> n;
  int num;
  int s = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &num);
    s += num - 1;
    cout << 2 - s % 2 << '\n';
  }
  return 0;
}
