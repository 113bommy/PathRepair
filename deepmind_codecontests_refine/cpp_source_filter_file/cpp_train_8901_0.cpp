#include <bits/stdc++.h>
using namespace std;
long long cache[1000 * 1000] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int seg(int n) {
  long long& ret = cache[n];
  if (ret != 0) return ret;
  return ret = cache[n % 10] + seg(n / 10);
}
void solve(int a, int b) {
  long long ret = 0;
  for (int i = a; i <= b; i++) ret += seg(i);
  cout << ret << endl;
}
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  solve(a, b);
}
