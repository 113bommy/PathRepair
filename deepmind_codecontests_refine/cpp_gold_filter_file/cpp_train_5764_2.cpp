#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using std::cerr;
using std::cin;
using std::cos;
using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::next_permutation;
using std::pair;
using std::priority_queue;
using std::queue;
using std::random_shuffle;
using std::set;
using std::sin;
using std::sort;
using std::sqrt;
using std::stack;
using std::string;
using std::stringstream;
using std::swap;
using std::vector;
const long double PI = 3.14159265358979323846;
const double eps = 1e-12;
int m;
int pow(int n) {
  long long res = 1;
  long long mul = 3;
  while (n) {
    if (n & 1) res = (res * mul) % m;
    mul = (mul * mul) % m;
    n >>= 1;
  }
  return res;
}
int main() {
  int n;
  cin >> n >> m;
  cout << (pow(n) + m - 1) % m << endl;
  return 0;
}
