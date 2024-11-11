#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
long long l, r;
vector<long long> vec;
void GenLucky(long long x) {
  if (x > (long long)1e12) return;
  if (x != 0) vec.push_back(x);
  GenLucky(x * 10 + 4);
  GenLucky(x * 10 + 7);
}
int solve() {
  scanf("%I64d%I64d", &l, &r);
  GenLucky(0ll);
  sort(vec.begin(), vec.end());
  long long sum = 0;
  for (long long &x : vec) {
    if (l > r) break;
    if (l > x) continue;
    sum += min(x - l + 1, r - l + 1) * x;
    l = x + 1;
  }
  printf("%I64d", sum);
  return 0;
}
int main() { solve(); }
