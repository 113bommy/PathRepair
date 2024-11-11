#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int f, r, a, m, v;
  cin >> f >> r >> a >> m >> v;
  cout << min(f, min(r, min(a / 2, min(m / 7, v / 5))));
}
