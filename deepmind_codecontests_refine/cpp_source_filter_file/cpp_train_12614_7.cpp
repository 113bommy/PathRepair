#include <bits/stdc++.h>
using namespace std;
int n, t, o, k, p, q, s;
map<int, int> M;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t), o ^= t & 1;
    p ^= (i - 1) & 1;
    if (t == 0) k++;
    M[t]++;
  }
  if (n == 1 && t == 0) {
    printf("cslnb");
    return 0;
  }
  for (auto j : M) {
    s += j.second - 1;
    if (j.second > 1) q = j.first;
  }
  if (k > 1 && n > k) {
    puts("cslnb");
    return 0;
  }
  if (s > 1 || s == 1 && M.count(q - 1)) {
    puts("cslnb");
    return 0;
  }
  puts(o ^ p ? "sjfnb" : "cslnb");
  return 0;
}
