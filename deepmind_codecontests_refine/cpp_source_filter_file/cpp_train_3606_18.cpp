#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
const double eps = 1e-9;
long long INF = 1e9 + 7;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
bool comp(pair<int, double> a, pair<int, double> b) {
  if (a.second > b.second)
    return true;
  else if (a.second < b.second)
    return false;
  else
    return a.first < b.first;
}
struct compare {
  bool operator()(const long long& l, const long long& r) { return l > r; }
};
void read(string str, int node) {
  stringstream ss;
  int number;
  ss << str;
  while (ss >> number) cout << number << endl;
}
long long fp(long long b, long long p) {
  if (p == 0) return 1;
  if (p % 2 == 0) return fp((b * b) % INF, p / 2);
  return (fp(b, p - 1) * b) % INF;
}
long long read_binary(string s) {
  unsigned long long x = 0, tmp = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    x = (x + tmp * (s[i] - '0')) % INF;
    tmp = (tmp * 2) % INF;
  }
  return x;
}
long long com(long long x, long long y) {
  long long sum = 1;
  for (int i = 1; i <= y; i++) {
    sum *= x;
    x--;
    sum /= i;
  }
  return sum;
}
long long gcd(long long n1, long long n2) {
  if (n2 != 0)
    return gcd(n2, n1 % n2);
  else
    return n1;
}
bool sum[1500];
void sieve() {
  sum[0] = sum[1] = 1;
  for (int i = 2; i * i < 1002; i++) {
    if (!sum[i]) {
      for (int j = 2 * i; j < 1002; j += i) {
        sum[j] = 1;
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;
    double a = sqrt(x);
    int b = sqrt(x);
    if (a != b) {
      res = max(res, (long long)x);
    }
  }
  cout << res;
  puts("");
}
