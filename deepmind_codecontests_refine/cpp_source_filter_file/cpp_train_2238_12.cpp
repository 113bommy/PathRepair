#include <bits/stdc++.h>
using namespace std;
struct piii {
  long long first, second, th;
  bool operator<(const piii &b) {
    if (first != b.first) return first < b.first;
    if (second != b.second) return second < b.second;
    return th < b.th;
  }
};
int x[1000005], y[1000005], p[1000005];
bool cmp(const int &a, const int &b) {
  if (x[a] / 1000 == x[b] / 1000) {
    if ((x[a] / 1000) % 2) return y[a] > y[b];
    return y[b] < y[a];
  }
  return x[a] < x[b];
}
int main() {
  cout << setprecision(2) << fixed;
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    p[i] = i;
  }
  sort(p, p + n, cmp);
  for (int i = 0; i < n; i++) cout << p[i] + 1 << ' ';
  return 0;
}
