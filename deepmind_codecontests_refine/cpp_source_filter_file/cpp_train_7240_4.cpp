#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<char> ve;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ve.push_back(x);
  }
  for (int i = 0; i < n - 1; i++) ve[i] += ve[i + 1];
  for (auto x : ve) printf("%d ", x);
  puts("");
  return 0;
}
