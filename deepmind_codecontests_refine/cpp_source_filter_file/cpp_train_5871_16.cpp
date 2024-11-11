#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
long long LCM(long long a, long long b) { return a * (b / GCD(a, b)); }
const double EPS = 10e-9;
const double INF = (1LL << 30);
using namespace std;
std::string int2str(int n) {
  std::ostringstream result;
  result << n;
  return result.str();
}
int str2int(const std::string& s) {
  int result;
  std::istringstream ss(s);
  ss >> result;
  if (!ss) throw std::invalid_argument("StrToInt");
  return result;
}
int main() {
  long long N;
  cin >> N;
  long long len = 2 * N - 1;
  long long sum = 0, minv = 1000;
  long long val = 0, neg = 0;
  for (int i = 0; i < (len); ++i) {
    cin >> val;
    if (val < 0) neg++;
    val = abs(val);
    sum += val;
    minv = min(minv, val);
  }
  if (N % 2 == 1 || (N % 2 == 0 && neg % 2 == 0)) {
    cout << sum << endl;
  } else {
    cout << sum - minv << endl;
  }
  return 0;
}
