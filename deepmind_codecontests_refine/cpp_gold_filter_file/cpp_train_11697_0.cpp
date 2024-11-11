#include <bits/stdc++.h>
using namespace std;
struct BIT {
  vector<int> fen;
  int size;
  BIT() { size = 0; }
  BIT(int n) {
    fen.resize(n + 2);
    size = n;
  }
  void upd(int x, int val) {
    for (; x <= size; x += x & (-x)) fen[x] += val;
  }
  int get(int x) {
    int res = 0;
    for (; x > 0; x -= x & (-x)) res += fen[x];
    return res;
  }
} lft, rig;
const int MAX_N = 100000 + 20;
int b[MAX_N];
map<int, int> D;
int a[MAX_N];
long long ans;
long long inv, k;
int n;
void readInput() {
  cin >> n >> k;
  for (int i(0); i < int(n); ++i) {
    cin >> b[i];
    a[i] = b[i];
  }
}
inline int f(const int &x) { return (n + 1) - x; }
void erase(int id) {
  inv -= rig.get(a[id] - 1) + lft.get(f(a[id]) - 1);
  rig.upd(a[id], -1);
}
void add(int id) {
  inv += rig.get(a[id] - 1) + lft.get(f(a[id]) - 1);
  lft.upd(f(a[id]), 1);
}
int main() {
  ios::sync_with_stdio(false);
  readInput();
  {
    sort(b, b + n);
    int temp = 1;
    for (int i(0); i < int(n); ++i)
      if (D[b[i]] == 0) D[b[i]] = temp++;
    for (int i(0); i < int(n); ++i) a[i] = D[a[i]];
  }
  lft = rig = BIT(n);
  for (int i(n - 1); i >= int(0); --i) {
    inv += rig.get(a[i] - 1);
    rig.upd(a[i], 1);
  }
  int tail = 0;
  for (int i(0); i < int(n); ++i) {
    while (tail < n && tail <= i) erase(tail++);
    add(i);
    while (tail < n && inv > k) erase(tail++);
    ans += n - tail;
  }
  cout << ans << endl;
  return 0;
}
