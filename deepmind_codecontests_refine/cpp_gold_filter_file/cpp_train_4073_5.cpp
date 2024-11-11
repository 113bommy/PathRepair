#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, container = 0;
  cin >> n >> m >> k;
  std::vector<int> box(n);
  for (auto &i : box) std::cin >> i;
  ;
  for (i = n - 1; i >= 0; i--) {
    if (container + box[i] > k) i++;
    if (container + box[i] >= k) {
      m--;
      container = 0;
    } else
      container += box[i];
    if (!m || !i) break;
  }
  cout << n - i;
}
