#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 1;; ++i) {
    x = x * (x + 1) / 2;
    if (x > n)
      break;
    else
      v.push_back(x);
  }
  for (int i = 0; i < v.size(); ++i)
    if (binary_search(v.begin(), v.end(), n - v[i])) {
      puts("YES");
      return 0;
    }
  puts("NO");
  return 0;
}
