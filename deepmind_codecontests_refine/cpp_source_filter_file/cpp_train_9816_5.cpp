#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[15];
int p[15];
void shift(int x) {
  p[0] += x;
  for (int i = 0; i < 15; ++i) {
    if (p[i] < i + 1) break;
    p[i + 1] += p[i] / (i + 1);
    p[i] %= (i + 1);
  }
  vector<int> vec;
  for (int i = 1; i <= 15; ++i) vec.push_back(i);
  for (int i = 14; i >= 0; --i) {
    a[i] = vec[p[i]];
    vec.erase(vec.begin() + p[i]);
  }
}
long long get_sum(int ind) {
  long long s = (long long)ind * (ind + 1) / 2;
  int bios = ((n - 14) > (1) ? (1) : (n - 14));
  for (int i = bios; i <= ind; ++i) {
    s += a[n - i] - (15 - (n - i));
  }
  return s;
}
void query(int l, int r) { cout << get_sum(r) - get_sum(l - 1) << endl; }
int main() {
  for (int i = 1; i <= 15; ++i) {
    a[15 - i] = i;
  }
  cin >> n >> m;
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      query(l, r);
    } else {
      int x;
      cin >> x;
      shift(x);
    }
  }
  return 0;
}
