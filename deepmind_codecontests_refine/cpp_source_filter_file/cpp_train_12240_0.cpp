#include <bits/stdc++.h>
using namespace std;
ifstream f("bb.in");
int n, m, aux, k;
int main() {
  cin >> n;
  cin >> m;
  cin >> k;
  if (k % (2 * m) == 0)
    cout << ((k + 1) / 2) / m << " " << m << " ";
  else
    cout << (k + 1) / (m * 2) + 1 << " " << ((k + 1) / 2) % m << " ";
  if (k % 2)
    cout << "L";
  else
    cout << "R";
}
