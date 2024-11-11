#include <bits/stdc++.h>
using namespace std;
using std::cin;
ifstream in;
ofstream out;
ostringstream oss;
std::streambuf *coutbuf;
long long mod_pow(long long x, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x;
      res %= mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (b > 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long stein_gcd(long long a, long long b) {
  unsigned c = 0;
  while (1) {
    if (a == 0)
      return b << c;
    else if (b == 0)
      return a << c;
    if (!(a & 1) && !(b & 1)) {
      a >>= 1;
      b >>= 1;
      ++c;
    } else if (!(a & 1) && (b & 1)) {
      a >>= 1;
    } else if ((a & 1) && !(b & 1)) {
      b >>= 1;
    } else if ((a & 1) && (b & 1)) {
      unsigned tmp = a > b ? b : a;
      a = a > b ? a - b : (b - a);
      b = tmp;
    }
  }
}
tuple<int, int, int> xgcd(int a, int b) {
  int x = 0, y = 1, px = 1, py = 0;
  while (b != 0) {
    int q = a / b;
    int tx = x;
    x = px - q * x;
    px = tx;
    int ty = y;
    y = py - q * y;
    py = ty;
    int r = a % b;
    a = b;
    b = r;
  }
  return make_tuple(a, px, py);
}
int snake_find(int limit, vector<int> a) {
  int n = a.size();
  int t = 0, s = 0, sum = 0;
  int res = n + 1;
  while (1) {
    while (t < n && sum < limit) {
      sum += a[t++];
    }
    if (sum < limit) {
      break;
    }
    res = min(res, t - s + 1);
    sum -= a[s++];
  }
  return res;
}
vector<int> id;
vector<int> sz;
int groups;
void init(int n) {
  groups = n;
  id = vector<int>(n, 0);
  for (int i = 0; i < n; i++) {
    id[i] = i;
  }
  sz = vector<int>(n, 1);
}
int findRoot(int p) {
  while (p != id[p]) {
    id[p] = id[id[p]];
    p = id[p];
  }
  return p;
}
void comb(int p, int q) {
  int i = findRoot(p);
  int j = findRoot(q);
  if (i == j) {
    return;
  }
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
  groups--;
}
int rd() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int stage = 0;
string problem = "B";
long long solve() { return 1; }
int getS(long long a, long long b, long long c, long long d, int g) {
  long long l = ((a + b) % 2) ? a : (a + 1);
  long long h = ((c + b) % 2) ? c : (c - 1);
  long long z = (d - b) + 1;
  long long c1 = (h - l) / 2 + 1;
  long long l1 = ((a + b + 1) % 2) ? a : (a + 1);
  long long h1 = ((c + b + 1) % 2) ? c : (c - 1);
  long long c2 = (h1 - l1) / 2 + 1;
  long long s = z / 2 * (c1 + c2);
  if (z % 2) {
    s += c1;
  }
  if (g) {
    return s;
  } else {
    return (c - a + 1) * (d - b + 1) - s;
  }
}
void goforit() {
  int q;
  cin >> q;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    long long wh = getS(1, 1, m, n, 0);
    long long bl = getS(1, 1, m, n, 1);
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    long long c_black = getS(x1, y1, x2, y2, 1);
    long long c_white = getS(x3, y3, x4, y4, 0);
    long long x5, y5, x6, y6;
    if (max(x1, x3) <= min(x2, x4) && max(y1, y3) <= min(y2, y4)) {
      x5 = max(x1, x3);
      y5 = max(y1, y3);
      x6 = min(x2, x4);
      y6 = min(y2, y4);
      long long wt = getS(x5, y5, x6, y6, 1);
      c_black -= wt;
      bl -= c_black;
      wh += c_black;
      bl += c_white;
      wh -= c_white;
      cout << wh << " " << bl << endl;
    } else {
      bl -= c_black;
      wh += c_black;
      bl += c_white;
      wh -= c_white;
      cout << wh << " " << bl << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  goforit();
  return 0;
}
