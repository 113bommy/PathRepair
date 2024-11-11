#include <bits/stdc++.h>
using namespace std;
int f[35];
void putBits(int x) {
  for (int i = 0; i <= 31; i++) {
    if (x & (1 << i)) f[i]++;
  }
}
int getStripped(int x) {
  int mask = 0;
  for (int i = 0; i <= 31; i++) {
    if ((1 << i) & x)
      if (f[i] > 0) mask |= (1 << i);
  }
  return mask;
}
vector<int> v;
bool cmp(int a, int b) { return getStripped(a) > getStripped(b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    putBits(x);
    v.push_back(x);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
  return 0;
}
