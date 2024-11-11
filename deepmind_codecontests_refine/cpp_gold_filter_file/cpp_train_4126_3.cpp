#include <bits/stdc++.h>
using namespace std;
bool cal(int n, int x) {
  int sum = x;
  while (x) {
    sum += x % 10;
    x /= 10;
  }
  return sum == n;
}
vector<int> ret;
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 81; i > 0; i--)
    if (i < n && cal(n, n - i)) ret.push_back(n - i);
  printf("%u\n", ret.size());
  for (i = 0; i < ret.size(); i++) printf("%d\n", ret[i]);
  return 0;
}
