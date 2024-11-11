#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = ((1 << 31) - 1);
const long long LLINF = (((1LL << 63) - 1LL));
const double eps = 1e-9;
const double PI = 3.14159265358979323846;
int main() {
  long long a;
  long long b;
  cin >> a >> b;
  long long p10 = 1;
  while (p10 < b) {
    p10 *= 10LL;
  }
  vector<long long> check;
  check.push_back((p10 - 1) / 2);
  check.push_back(p10 / 2);
  check.push_back(a);
  check.push_back(b);
  for (int i = 0; i < check.size(); ++i) {
    if (a <= check[i] && check[i] <= b)
      check[i] = (p10 - 1 - check[i]) * check[i];
    else
      check[i] = -1;
  }
  cout << *max_element((check).begin(), (check).end()) << "\n";
  return 0;
}
