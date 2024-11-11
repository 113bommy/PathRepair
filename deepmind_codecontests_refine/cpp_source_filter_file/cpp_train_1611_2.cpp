#include <bits/stdc++.h>
using namespace std;
const int MAXI = numeric_limits<int>::max() / 2;
const int MINI = numeric_limits<int>::min() / 2;
const long long MAXL = numeric_limits<long long>::max() / 2;
const long long MINL = numeric_limits<long long>::min() / 2;
long long mul(long long a, long long b) {
  if (a > MAXL / b)
    return MAXL;
  else
    return a * b;
}
long long solve(long long t, long long a, long long b) {
  if (t > a) {
    return a == b ? 1 : 0;
  }
  vector<long long> co;
  long long tmp = b;
  while (tmp > 0) {
    co.push_back(tmp % a);
    tmp /= a;
  }
  long long r = 1, res = 0;
  for (int i = 0; i != co.size(); ++i) {
    tmp += mul(co[i], r);
    r = mul(r, t);
  }
  if (tmp == a) ++res;
  if (a == b) ++res;
  return res;
}
int main(int argc, char* argv[]) {
  long long t, a, b;
  cin >> t >> a >> b;
  if (t == 1) {
    if (a == 1) {
      if (b == 1)
        cout << "inf" << endl;
      else
        cout << 1 << endl;
    } else {
      if (a == b)
        cout << 1 << endl;
      else {
        long long tmp = a;
        while (tmp < b) {
          tmp = mul(tmp, a);
        }
        cout << (tmp == b ? 1 : solve(t, a, b)) << endl;
      }
    }
  } else
    cout << solve(t, a, b) << endl;
  return 0;
}
