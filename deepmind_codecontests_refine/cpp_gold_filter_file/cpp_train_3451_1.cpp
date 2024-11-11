#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MAX = 30;
long long x, num;
long long a[40];
bool check(long long x) {
  for (int i = 1; i < MAX; ++i) {
    if (a[i] == x) return 1;
  }
  return 0;
}
vector<int> ans;
int main() {
  long long x = 1;
  for (int i = 1; i < MAX; ++i) {
    x <<= 1;
    a[i] = x - 1;
  }
  scanf("%lld", &x);
  while (check(x) == 0) {
    int i;
    num++;
    for (i = MAX - 1; i >= 0; --i) {
      if (x >> i) break;
    }
    x ^= a[i + 1];
    ans.push_back(i + 1);
    if (check(x)) break;
    num++;
    x++;
  }
  printf("%d\n", num);
  for (auto i : ans) printf("%d ", i);
  return 0;
}
