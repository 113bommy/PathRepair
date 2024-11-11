#include <bits/stdc++.h>
using namespace std;
const int N = 300 + 7;
int m[N], c[N];
map<int, int> mp;
int gcd(int a, int b) { return (b != 0 ? gcd(b, a % b) : a); }
void add(int val, int cost) {
  if (!mp.count(val))
    mp[val] = cost;
  else
    m[val] = min(mp[val], cost);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> m[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) {
    for (auto it : mp) {
      add(gcd(m[i], it.first), c[i] + it.second);
    }
    add(m[i], c[i]);
  }
  if (mp.count(1))
    cout << mp[1] << endl;
  else
    cout << -1 << endl;
  return 0;
}
