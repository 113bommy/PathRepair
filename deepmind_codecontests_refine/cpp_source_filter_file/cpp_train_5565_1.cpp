#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 22;
int n, t[4 * N];
long long ANS = 0;
vector<int> pref, suff, v;
map<int, int> mp;
void update(int v, int vl, int vr, int pos, bool increase) {
  if (vl == vr) {
    if (increase)
      t[v]++;
    else
      t[v]--;
  } else {
    int vm = vl + (vr - vl) / 2;
    if (pos <= vm)
      update(2 * v + 1, vl, vm, pos, increase);
    else
      update(2 * v + 2, vm + 1, vr, pos, increase);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}
int get(int v, int vl, int vr, int l, int r) {
  if (vl > r || vr < l)
    return 0;
  else if (vl >= l && vr <= r)
    return t[v];
  else {
    int vm = vl + (vr - vl) / 2;
    return get(2 * v + 1, vl, vm, l, r) + get(2 * v + 2, vm + 1, vr, l, r);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  for (int i = n - 1; i > 0; i--) {
    mp[v[i]]++;
    suff.push_back(mp[v[i]]);
    update(0, 0, n, suff.back(), 1);
  }
  mp.clear();
  for (int i = 0; i < n - 1; i++) {
    mp[v[i]]++;
    pref.push_back(mp[v[i]]);
  }
  for (int i = 0; i < n - 1; i++) {
    ANS += get(0, 0, n - 1, 0, pref[i] - 1);
    update(0, 0, n - 1, suff[n - 2 - i], 0);
  }
  cout << ANS;
}
