#include <bits/stdc++.h>
using namespace std;
void yala_bena() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
}
const int m_r = 199999;
double pii = 3.1415926536;
int main() {
  yala_bena();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    if (k)
      cout << (2 * i) + 2 << " " << (2 * i) + 1, k--;
    else
      cout << (2 * i) + 1 << " " << (2 * i) + 2;
    if (i < n - 1) cout << " ";
  }
}
