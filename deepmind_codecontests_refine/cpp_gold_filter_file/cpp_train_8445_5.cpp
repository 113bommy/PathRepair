#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long toInt(string a) {
  stringstream ss;
  ss << a;
  long long res;
  ss >> res;
  return res;
}
string toS(long long a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
bool Eq(double a, double b) { return fabs(a - b) <= 1e-10; }
int bit(int x) { return x == 0 ? 0 : (x & 1) + bit(x >> 1); }
const int NN = 33, MM = 100900, INF = (1 << 26), Max = 1000000000;
vector<int> lucky;
void bkt(long long x) {
  if (x > Max) return;
  lucky.push_back(x);
  bkt(x * 10 + 4);
  bkt(x * 10 + 7);
}
bool isLucky(int a) {
  do {
    if (a % 10 != 7 && a % 10 != 4) return false;
    a /= 10;
  } while (a);
  return true;
}
bool isLess(string &b, string &a) {
  if (((int)a.size()) != ((int)b.size()))
    return ((int)a.size()) < ((int)b.size());
  return a < b;
}
int pre[NN];
int main() {
  bkt(4);
  bkt(7);
  sort(lucky.begin(), lucky.end());
  int pl, pr, vl, vr, K;
  scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &K);
  double ans = 0.;
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < ((int)lucky.size()); i++) {
      if (i + K <= ((int)lucky.size())) {
        long long L = lucky[i], R = lucky[i + K - 1];
        long long preL = i > 0 ? lucky[i - 1] + 1 : -1;
        long long LeftMin = max(pl, preL), LeftMax = min(pr, L);
        long long nexR =
            i + K < ((int)lucky.size()) ? lucky[i + K] - 1 : Max + 10;
        long long RightMax = min(vr, nexR), RightMin = max(vl, R);
        if (LeftMin <= LeftMax && RightMin <= RightMax) {
          double p1, p2;
          if (z == 1 && RightMin == LeftMax) {
            if (RightMin + 1 <= RightMax) {
              p1 = (double)(LeftMax - LeftMin + 1) / (pr - pl + 1);
              p2 = (double)(RightMax - RightMin) / (vr - vl + 1);
              ans += (p1 * p2);
            }
            if (LeftMax - 1 >= LeftMin) {
              p1 = (double)(LeftMax - LeftMin) / (pr - pl + 1);
              p2 = (double)(1.) / (vr - vl + 1);
              ans += (p1 * p2);
            }
          } else {
            p1 = (double)(LeftMax - LeftMin + 1) / (pr - pl + 1);
            p2 = (double)(RightMax - RightMin + 1) / (vr - vl + 1);
            ans += (p1 * p2);
          }
        }
      }
    }
    swap(pl, vl);
    swap(pr, vr);
  }
  printf("%.20f\n", ans);
  return 0;
}
