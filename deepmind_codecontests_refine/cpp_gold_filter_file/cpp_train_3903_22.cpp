#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> t;
  while (n) {
    t.push_back(n % 10);
    n /= 10;
  }
  reverse(t.begin(), t.end());
  int res = 0;
  for (int i = 0; i < t.size(); ++i) {
    res = res * 2 + (t[i] == 4 ? 1 : 2);
  }
  printf("%d\n", res);
  return 0;
}
