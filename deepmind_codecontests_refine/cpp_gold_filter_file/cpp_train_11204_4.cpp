#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
const int sq = 100;
const long long int mod = 1e9 + 7;
const long long int inf = 1e16;
bool mark[N];
int seg[4 * N], n;
void add(int x, int b = 0, int e = n, int ind = 1) {
  if (b + 1 == e) {
    seg[ind]++;
    return;
  }
  int mid = (b + e) / 2;
  if (x < mid)
    add(x, b, mid, ind * 2);
  else
    add(x, mid, e, ind * 2 + 1);
  seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}
int get(int l, int r, int b = 0, int e = n, int ind = 1) {
  if (r <= b || e <= l) return 0;
  if (l <= b && e <= r) return seg[ind];
  int mid = (b + e) / 2;
  return get(l, r, b, mid, ind * 2) + get(l, r, mid, e, ind * 2 + 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  int pt = n;
  cout << 1 << ' ';
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    p--;
    mark[p] = 1;
    add(p);
    while (pt > 0 && mark[pt - 1]) pt--;
    cout << 1 + get(0, pt) << ' ';
  }
  cout << endl;
  return 0;
}
