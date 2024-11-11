#include <bits/stdc++.h>
using namespace std;
long long int M = 1000000007;
long long int gcd(long long int a, long long int b) {
  if (b < a) {
    long long int temp = a;
    a = b;
    b = temp;
  }
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a * b / gcd(a, b));
}
vector<long long int> getprimes() {
  vector<long long int> pl(101, 1);
  for (int i = 2; i <= 100; i++) {
    if (pl[i] == 1) {
      for (int j = 2 * i; j <= 100; j += i) {
        pl[j] = 0;
      }
    }
  }
  return pl;
}
double distsqrd(double x1, double y1, double x2, double y2) {
  return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
long long int fact(long long int first) {
  long long int ans = 1;
  if (first == 0) {
    return 1;
  }
  while (first > 0) {
    ans = (ans * first) % 1000000007;
    first--;
  }
  return ans % 1000000007;
}
long long int power(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      ans *= a;
      ans = ans % m;
    }
    b /= 2;
    a *= a;
    a = a % m;
  }
  return ans % m;
}
vector<int> getbinary(int first) {
  vector<int> bin(10, 0);
  int iter = 0;
  while (first > 0) {
    if (first % 2 == 1) {
      bin[iter] = 1;
    } else {
      bin[iter] = 0;
    }
    iter++;
    first /= 2;
  }
  return bin;
}
int getnum(vector<int> bin) {
  int t = 1;
  int n = bin.size();
  int ret = 0;
  for (int i = 0; i < n; i++) {
    ret += t * bin[i];
    t *= 2;
  }
  return ret;
}
long long big_multiply(long long a, long long b, long long m) {
  a %= m;
  b %= m;
  long long res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
}
void dfs(int start, map<int, vector<int> > g, double num[], double depth[]) {
  num[start] = 1;
  for (auto v : g[start]) {
    depth[v] = depth[start] + 1;
    dfs(v, g, num, depth);
    num[start] += num[v];
  }
}
struct point {
  int first, second, ind;
};
bool comparator(const point &a, const point &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int x1, y1, x2, y2;
  long long int a, b;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  a *= 2;
  b *= 2;
  long long int sectorx1 = (x1 + y1) / a + ((x1 + y1) > 0);
  long long int sectory1 = (x1 - y1) / a + ((x1 - y1) > 0);
  long long int sectorx2 = (x2 + y2) / b + ((x2 + y2) > 0);
  long long int sectory2 = (x2 - y2) / b + ((x2 - y2) > 0);
  cout << max(abs(sectory2 - sectory1), abs(sectorx2 - sectorx1));
}
