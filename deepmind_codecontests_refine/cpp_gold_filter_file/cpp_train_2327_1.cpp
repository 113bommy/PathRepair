#include <bits/stdc++.h>
using namespace std;
vector<long long> dpF[100000 + 1];
vector<long long> dpB[100000 + 1];
long long maxS[100000 + 1];
long long res(long long x) {
  if (x < 10) return x;
  long long last = x % 10;
  long long k = 9 + (x - 10) / 10;
  while (x > 9) x /= 10;
  if (last >= x) k++;
  return k;
}
void solve() {
  long long n;
  cin >> n;
  map<long long, int> front, back, total, common;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    front[a]++;
    back[b]++;
    total[a]++;
    total[b]++;
    if (a == b) common[a]++;
  }
  long long req = (n + 1) / 2;
  for (auto it = front.begin(); it != front.end(); it++) {
    if (it->second >= req) {
      cout << 0 << endl;
      return;
    }
  }
  long long res = LONG_LONG_MAX;
  for (auto it = total.begin(); it != total.end(); it++) {
    long long k = it->first;
    long long a = front[k];
    long long b = back[k];
    long long joie6e = req - a;
    long long padya6e = b - common[k];
    if (padya6e >= joie6e) res = min(res, joie6e);
  }
  cout << ((res == LONG_LONG_MAX) ? -1 : res) << endl;
}
int main() { solve(); }
