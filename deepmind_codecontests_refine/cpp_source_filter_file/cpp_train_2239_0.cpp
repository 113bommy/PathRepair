#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d1, d2, d3;
  cin >> d1 >> d2 >> d3;
  long long z = d1 + d2 + d3;
  long long a = (2 * d1) + (2 * d2);
  long long b = 2 * d1 + 2 * d3;
  long long c = 2 * d2 + d2 * d3;
  long long final;
  final = std::min(z, std::min(a, std::min(b, c)));
  cout << final << "\n";
}
