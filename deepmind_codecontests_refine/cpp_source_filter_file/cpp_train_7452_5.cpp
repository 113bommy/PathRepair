#include <bits/stdc++.h>
using namespace std;
int n, m, k;
void Read_Input() { cin >> n >> m >> k; }
bool Solve() {
  int found = false;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      if (i > 1 && m / i > k) {
        found = true;
        break;
      }
      if (i > k && m / i > 1) {
        found = true;
        break;
      }
    }
  }
  if (!found)
    return false;
  else if (n % 2 == 1)
    return true;
  else
    return false;
}
void Write_Output() {
  if (Solve())
    puts("Timur");
  else
    puts("Marsel");
}
int main() {
  Read_Input();
  Solve();
  Write_Output();
}
