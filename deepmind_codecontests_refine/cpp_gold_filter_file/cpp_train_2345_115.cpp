#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)LLONG_MAX;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int dx8[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy8[8] = {0, 0, 1, -1, 1, -1, 1, -1};
long long ipow(long long base, long long exp) {
  long long result = 1;
  while (exp) {
    if (exp & 1) result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}
string tos(long long n) {
  stringstream ss;
  string ans;
  ss << n;
  ss >> ans;
  return ans;
}
long long toll(string n) { return atoll(n.c_str()); }
double dist(double x1, double y1, double x2, double y2) {
  return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}
int doubleCompare(double x, double y) {
  if (fabs(x - y) <= 1e-18) return 0;
  if (x < y) return -1;
  return 1;
}
int main() {
  long long n;
  cin >> n;
  cout << n / 2520;
}
