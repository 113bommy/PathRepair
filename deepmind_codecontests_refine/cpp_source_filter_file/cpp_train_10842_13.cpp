#include <bits/stdc++.h>
using namespace std;
bool is_fourier(int id) { return ((min(id, 25) + id) % (2 + id % 3)) > 0; }
int main() {
  for (int i = 1; i <= 20; ++i) {
    if (is_fourier(i))
      cout << 1;
    else
      cout << 0;
    cout << '\n';
  }
}
