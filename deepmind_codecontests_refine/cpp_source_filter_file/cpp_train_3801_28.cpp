#include <bits/stdc++.h>
const double eps = (1e-5);
using namespace std;
int dcmp(long double a, long double b) {
  return fabsl(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
long long getBit(long long num, int idx) { return ((num >> idx) & 1ll) == 1; }
int setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
long long val;
vector<pair<long long, long long> > ans;
long long mod = (1ll << 60);
long double p[5];
long long check(long double n, long double val) {
  long double g = n;
  g -= 1;
  long double L = (g * (g + 1)) / 2;
  p[0] = (n * L);
  p[2] = (g * (g + 1) * (2 * g + 1)) / 6;
  long double m = (val - p[2] + p[0]) / ((n * (g + 1)) - L);
  if (n < m && ceil(m) == floor(m)) return m;
  return -1;
}
int main() {
  M();
  cin >> val;
  long long mi = mod;
  for (int i = 1; i <= 10000000; i++) {
    if (i >= mi) break;
    long long m = check(i, val);
    if (m == -1) continue;
    mi = min(mi, m);
    ans.push_back(make_pair(i, m));
    if (i != m) {
      ans.push_back(make_pair(m, i));
    }
  }
  sort(((ans).begin()), ((ans).end()));
  cout << ((int)(ans).size()) << endl;
  for (int i = 0; i < ((int)(ans).size()); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
}
