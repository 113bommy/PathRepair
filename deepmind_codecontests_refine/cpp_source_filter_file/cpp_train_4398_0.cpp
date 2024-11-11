#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
using pii = pair<int, int>;
int h, g;
vector<int> a;
map<int, int> heap;
int valToI[(1 << 20) + 1];
vector<int> vals;
int sum;
int size_orig, size_target;
vector<int> ops;
int depth(int index) {
  int top_dist = floor(log2(index)) + 1, bot_dist = 0;
  while (1) {
    int l = index << 1, r = l + 1;
    if (l > (1 << h) - 1 || r > (1 << h) - 1 || a[l] == 0 && a[r] == 0) break;
    if (a[l] > a[r])
      index = l;
    else
      index = r;
    bot_dist++;
  }
  return bot_dist + top_dist;
}
void f(int index) {
  while (1) {
    int l = index << 1, r = l + 1;
    if (l > (1 << h) - 1 || r > (1 << h) - 1 || a[l] == 0 && a[r] == 0) {
      a[index] = 0;
      break;
    }
    if (a[l] > a[r]) {
      valToI[a[l]] = index;
      a[index] = a[l];
      index = l;
    } else {
      valToI[a[r]] = index;
      a[index] = a[r];
      index = r;
    }
  }
  size_orig--;
}
void solve() {
  for (auto valIter = --vals.end(); size_orig > size_target; --valIter) {
    if (valToI[*valIter] == -1 || depth(valToI[*valIter]) == g) continue;
    sum -= *valIter;
    f(valToI[*valIter]);
    ops.push_back(valToI[*valIter]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 0; i < ((1 << 20) + 1); i++) valToI[i] = -1;
  while (T--) {
    cin >> h >> g;
    size_orig = (1 << h) - 1;
    size_target = (1 << g) - 1;
    for (auto val : vals) valToI[val] = -1;
    a.clear();
    a.reserve(size_orig + 1);
    vals.clear();
    ops.clear();
    sum = 0;
    for (int i = 0; i < (size_orig); i++) {
      cin >> a[i + 1];
      sum += a[i + 1];
      valToI[a[i + 1]] = i + 1;
      vals.push_back(a[i + 1]);
    }
    sort(vals.begin(), vals.end());
    solve();
    cout << sum << endl;
    for (auto i : ops) cout << i << " ";
    cout << endl;
  }
  return 0;
}
