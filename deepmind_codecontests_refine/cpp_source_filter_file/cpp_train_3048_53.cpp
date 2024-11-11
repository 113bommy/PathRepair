#include <bits/stdc++.h>
using namespace std;
int main() {
  size_t n;
  int a, b;
  cin >> n;
  for (size_t i = 0; i < n; ++i) {
    cin >> a >> b;
    bitset<32> b_a(a);
    bitset<32> b_b(b);
    bitset<32> x_b(0);
    for (size_t j = 0; j < 32; ++j) {
      if (b_a[j] == b_b[j])
        x_b[j] = b_a[j];
      else
        x_b[j] = 0;
    }
    int x = (int)x_b.to_ulong();
    auto res = (a ^ x) + (b ^ x);
    cout << res;
  }
}
