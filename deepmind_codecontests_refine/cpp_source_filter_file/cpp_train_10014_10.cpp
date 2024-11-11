#include <bits/stdc++.h>
using namespace std;
long long int INF = 3e18;
double Pi = 3.1415926535897932384626;
vector<long long> G[550010];
priority_queue<long long> pql;
priority_queue<pair<long long, long long> > pqp;
priority_queue<long long, vector<long long>, greater<long long> > pqls;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    pqps;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
char dir[] = "DRUL";
long long mod = 998244353;
long long rui(long long number1, long long number2) {
  if (number2 == 0) {
    return 1;
  } else {
    long long number3 = rui(number1, number2 / 2);
    number3 *= number3;
    number3 %= mod;
    if (number2 % 2 == 1) {
      number3 *= number1;
      number3 %= mod;
    }
    return number3;
  }
}
long long gcd(long long number1, long long number2) {
  if (number1 > number2) {
    swap(number1, number2);
  }
  if (number1 == 0 || number1 == number2) {
    return number2;
  } else {
    return gcd(number2 % number1, number1);
  }
}
void YES(bool condition) {
  if (condition) {
    cout << "YES"
         << "\n";
    ;
  } else {
    cout << "NO"
         << "\n";
    ;
  }
  return;
}
void Yes(bool condition) {
  if (condition) {
    cout << "Yes"
         << "\n";
    ;
  } else {
    cout << "No"
         << "\n";
    ;
  }
  return;
}
long long n, m, num, sum, a, b, c, d, e, g, h, w, i, j, q, r, l;
long long k, ans;
long long x[500005], y[500005], z[500005];
bool used[500005];
char s[500005];
struct SegmentTree {
 private:
  long long n;
  vector<long long> node;

 public:
  SegmentTree(vector<long long> v) {
    long long sz = v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, 0);
    for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      node[i] = max(node[2 * i + 1], node[2 * i + 2]);
  }
  void update(long long x, long long val) {
    x += (n - 1);
    node[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = max(node[2 * x + 1], node[2 * x + 2]);
    }
  }
  long long getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return node[k];
    long long vl = getmax(a, b, 2 * k + 1, l, (l + r) / 2);
    long long vr = getmax(a, b, 2 * k + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
};
void muri() {
  for (int i = 0; i < n; i++) {
    cout << (-1) << " ";
    ;
  }
  cout << endl;
  ;
  return;
}
int main() {
  cin >> n;
  SegmentTree seg(vector<long long>(3 * n + 5, 0));
  long long large = 0;
  long long small = INF;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    large = max(large, x[i]);
    small = min(small, x[i]);
    seg.update(i, x[i]);
  }
  if (large <= small * 2) {
    muri();
    return 0;
  }
  for (int i = 0; i < n; i++) {
    x[i + n] = x[i];
    seg.update(i + n, x[i]);
  }
  for (int i = 0; i < n; i++) {
    x[i + 2 * n] = x[i];
    seg.update(i + 2 * n, x[i]);
  }
  long long right = 0;
  for (int left = 0; left < n; left++) {
    while (right < 2 * n && (seg.getmax(left, right + 2) <= 2 * x[right + 1])) {
      right++;
    }
    cout << (right - left + 1) << " ";
    ;
    if (right == left) right++;
  }
  cout << endl;
  ;
  return 0;
}
