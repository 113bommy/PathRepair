#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 5;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long a[N], b[N];
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  if (n > 36) {
    cout << -1 << endl;
    return 0;
  }
  string s = "";
  if (n % 2 == 0) {
    while (n) {
      s += "8";
      n -= 2;
    }
  } else {
    s += "4";
    n -= 1;
    while (n) {
      s += "8";
      n -= 2;
    }
  }
  cout << s << endl;
  return 0;
}
