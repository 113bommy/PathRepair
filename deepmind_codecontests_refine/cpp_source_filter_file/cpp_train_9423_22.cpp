#include <bits/stdc++.h>
using namespace std;
int treea[500000], treeb[500000], n, k, a, b, q;
void Update(int pos, int val) {
  pos += n;
  treea[pos] = min(treea[pos] + val, a);
  treeb[pos] = min(treeb[pos] + val, b);
  for (int i = pos; pos > 1; pos /= 2) {
    treea[pos / 2] = treea[pos] + treea[pos ^ 1];
    treeb[pos / 2] = treeb[pos] + treeb[pos ^ 1];
  }
}
int querya(int l, int r) {
  if (l >= r) return 0;
  int sum = 0;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l & 1) sum += treea[l++];
    if (r & 1) sum += treea[--r];
  }
  return sum;
}
int queryb(int l, int r) {
  if (l >= r) return 0;
  int sum = 0;
  for (l += n, r += n; l < r; l /= 2, r /= 2) {
    if (l & 1) sum += treeb[l++];
    if (r & 1) sum += treeb[--r];
  }
  return sum;
}
void solve() {
  int tmp, di, ai, pi;
  cin >> n >> k >> a >> b >> q;
  for (int i = 0; i < q; i++) {
    cin >> tmp;
    if (tmp == 1) {
      cin >> di >> ai;
      Update(di, ai);
    } else {
      cin >> pi;
      cout << queryb(0, pi - 1) + querya(pi + k, n + 1) << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
