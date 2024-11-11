#include <bits/stdc++.h>
using namespace std;
int a[300007];
bool check[300007];
int main() {
  int n;
  scanf("%d", &n);
  for (auto i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  vector<int> inc, dec;
  for (auto i = (1); i <= (n); ++i) {
    bool u = 0, v = 0;
    if (inc.empty() || a[i] > a[inc.back()]) u = 1;
    if (dec.empty() || a[i] < a[dec.back()]) v = 1;
    if (u && v) {
      if (a[i] > a[i + 1])
        dec.emplace_back(i);
      else
        inc.emplace_back(i);
    } else if (u)
      inc.emplace_back(i);
    else if (v)
      dec.emplace_back(i);
    else {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (auto i = (0); i <= ((int)inc.size() - 1); ++i) check[inc[i]] = 1;
  for (auto i = (1); i <= (n); ++i) printf("%d ", 1 - check[i]);
  return 0;
}
