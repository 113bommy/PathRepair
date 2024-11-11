#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d", &n);
  vector<int> a;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    b.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long sa = 0, sb = 0;
  while (a.size() > 0 || b.size() > 0) {
    if (a.size() == 0)
      b.pop_back();
    else if (b.size() == 0 || a.back() > b.back()) {
      sa += a.back();
      a.pop_back();
    } else
      b.pop_back();
    if (b.size() == 0)
      a.pop_back();
    else if (a.size() == 0 || b.back() > a.back()) {
      sb += b.back();
      b.pop_back();
    } else
      a.pop_back();
  }
  printf("%I64d\n", sa - sb);
}
