#include <bits/stdc++.h>
using namespace std;
struct devil {
  long long l;
  long long r;
  long long ind;
};
const int N = 400000;
int bit[N];
int pres(int idx) {
  int ans = 0;
  while (idx > 0) {
    ans = ans + bit[idx];
    idx = idx - (idx & -idx);
  }
  return ans;
}
void update(int idx, int val, int n) {
  while (idx <= n) {
    bit[idx] = bit[idx] + val;
    idx = idx + (idx & -idx);
  }
}
int rsm(int l, int r) { return pres(r) - pres(l - 1); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<devil> vect;
  long long n;
  cin >> n;
  map<long long, long long> mp, mp1;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    mp[x]++;
    mp[y]++;
    vect.push_back({x, y, i + 1});
  }
  long long z = 1;
  for (auto i : mp) {
    mp1[i.first] = z++;
  }
  sort(vect.begin(), vect.end(),
       [](const devil& p1, const devil& p2) { return p1.l < p2.l; });
  map<long long, long long> mp3;
  for (long long i = n - 1; i >= 0; i--) {
    mp3[vect[i].ind] = rsm(mp1[vect[i].l], mp1[vect[i].r]);
    update(mp1[vect[i].r], 1, N - 5);
  }
  for (auto i : mp3) {
    cout << i.second << '\n';
  }
  return 0;
}
