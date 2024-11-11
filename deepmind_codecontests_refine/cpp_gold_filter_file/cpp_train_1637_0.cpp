#include <bits/stdc++.h>
using namespace std;
bool debug = true;
long long n, m, a, b;
int main(int argc, char* argv[]) {
  cin >> n >> m >> a >> b;
  long long r = n % m;
  cout << min(r * b, (m - r) * a);
  return 0;
}
