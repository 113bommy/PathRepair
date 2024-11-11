#include <bits/stdc++.h>
using namespace std;
int ans[100];
int f(int a) {
  if (a == 0) return 0;
  if (a == 1) return 1;
  if (a % 2 == 0)
    return f(a / 2);
  else
    return f((a - 1) / 2) + 1;
}
int main() {
  int n, a;
  long long r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    a = f(a);
    ans[a]++;
  }
  for (int i = 0; i < 100; i++) r += ans[i] * (ans[i] - 1) / 2;
  cout << r << endl;
  return 0;
}
