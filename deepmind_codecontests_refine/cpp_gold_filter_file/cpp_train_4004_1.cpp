#include <bits/stdc++.h>
using namespace std;
using std::string;
long long power(long long b, long long p) {
  if (p == 0) return 1;
  long long ans = 1;
  while (p > 1) {
    if (p % 2 == 0) {
      b *= b;
      p /= 2;
    } else {
      ans *= b;
      p -= 1;
    }
  }
  ans *= b;
  return ans;
}
vector<long long> v;
bool chk(int i, int x) {
  long long s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }
  if (s == i) return true;
  return false;
}
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  for (int(i) = 1; (i) <= (81); ++(i)) {
    long long x = power(i, a) * b + c;
    if (x < 1000000000 && chk(i, x)) {
      v.push_back(x);
    }
  }
  cout << v.size() << endl;
  for (int(i) = 0; (i) < (v.size()); ++(i)) cout << v[i] << " ";
}
