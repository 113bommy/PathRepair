#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
class node {
 public:
  int f1;
  node *left;
  node *right;
  node(int f1) {
    this->f1 = f1;
    this->left = nullptr;
    this->right = nullptr;
  }
};
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
struct compare {
  bool operator()(node const &i1, node const &i2) { return (i1.f1 > i2.f1); }
};
bool IsApproximatelyEqual(double x, double y, double epsilon) {
  if ((-epsilon <= (x - y)) && ((x - y) <= epsilon)) return true;
  if (((-epsilon <= x) && (x <= epsilon)) ||
      ((-epsilon <= y) && (y <= epsilon)))
    return false;
  return ((-epsilon <= ((x - y) / x)) && (((x - y) / x) <= epsilon)) ||
         ((-epsilon <= ((x - y) / y)) && (((x - y) / y) <= epsilon));
}
bool compareInterval(node i1, node i2) { return (i1.f1 < i2.f1); }
long long getlen(char *s) {
  long long k = 0;
  while (*s != '\0') {
    s += 1;
    k += 1;
  }
  return k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, a, b, x, y, co, n, t1, aa, bb, nn;
  long long ans1, ans2;
  cin >> t;
  while (t-- > 0) {
    cin >> a >> b >> x >> y >> n;
    co = 0;
    aa = a;
    bb = b;
    nn = n;
    t1 = min(n, b - y);
    n -= t1;
    b -= (t1);
    if (n <= 0) {
      ans1 = a * b;
    } else {
      t1 = min(n, a - x);
      n -= (t1);
      a -= t1;
      ans1 = a * b;
    }
    a = aa;
    b = bb;
    n = nn;
    swap(a, b);
    swap(x, y);
    t1 = min(n, b - y);
    n -= t1;
    b -= (t1);
    if (n <= 0) {
      ans2 = a * b;
    } else {
      t1 = min(n, a - x);
      n -= (t1);
      a -= t1;
      ans2 = a * b;
    }
    cout << min(ans1, ans2) << endl;
  }
}
