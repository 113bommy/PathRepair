#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)LLONG_MAX;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int dx8[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
int dy8[9] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
long long ipow(long long base, long long exp, long long mod) {
  long long result = 1;
  base %= mod;
  while (exp) {
    if (exp & 1) result = (result * base) % mod;
    exp >>= 1;
    base = (base * base) % mod;
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
  if (fabs(x - y) <= 1e-100) return 0;
  if (x < y) return -1;
  return 1;
}
long long arr[300005];
long long arr2[300005];
int main() {
  int n, t, type, x;
  cin >> n >> t;
  long long sum = 0;
  queue<int> que;
  int mx = 0;
  for (int i = 1; i <= t; i++) {
    cin >> type >> x;
    bool f = 0;
    if (type == 1) {
      sum++;
      arr[x]++;
      que.push(x);
    } else if (type == 2) {
      sum -= arr[x];
      arr2[x] += arr[x];
      arr[x] = 0;
    } else if (type == 3) {
      for (; mx < x; mx++) {
        if (que.empty()) break;
        int tmp = que.front();
        que.pop();
        if (arr2[tmp] > 0) {
          arr2[tmp]--;
        } else {
          arr[tmp]--;
          sum--;
        }
      }
    }
    cout << max(0LL, sum) << "\n";
  }
}
