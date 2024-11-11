#include <bits/stdc++.h>
using namespace std;
int h1, a1, c2, h2, a2, dem, maxh;
int A1, C2, H2, A2, H1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h1 >> a1 >> a2 >> h2 >> c2;
  H1 = h1, A1 = a1, A2 = a1, H2 = h2, C2 = c2;
  while (H2 > 0) {
    dem++;
    if (A1 >= H2)
      H2 -= A1;
    else if (H1 > C2)
      H1 -= C2, H2 -= A1;
    else
      H1 += A2 - C2;
  }
  cout << dem << "\n";
  while (h2 > 0) {
    if (a1 >= h2)
      h2 -= a1, cout << "STRIKE\n";
    else if (h1 > c2)
      h1 -= c2, h2 -= a1, cout << "STRIKE\n";
    else
      h1 += a2 - c2, cout << "HEAL\n";
  }
}
