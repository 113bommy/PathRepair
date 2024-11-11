#include <bits/stdc++.h>
using namespace std;
long long l, r;
int k;
void solve1() {
  cout << l << "\n";
  cout << "1\n" << l;
  exit(0);
}
void solve2() {
  if (l % 2LL == 1 && l + 1 < r) l++;
  if (l % 2LL == 0) {
    cout << "1\n2\n";
    cout << l << " " << l + 1;
    exit(0);
  }
  if (l <= (l ^ r))
    solve1();
  else {
    cout << (l ^ r) << "\n2\n";
    cout << l << " " << r;
  }
  exit(0);
}
void solve3() {
  for (long long x = 1; x <= r; x *= 2LL) {
    long long nxt = x * 2LL;
    if (nxt - 1 >= l && nxt + x <= r) {
      cout << "0\n3\n";
      cout << nxt - 1 << " " << nxt + x - 1 << " " << nxt + x;
      exit(0);
    }
  }
  solve2();
}
void solve4() {
  for (long long x = l; x + 3 <= r; x++) {
    if ((x ^ (x + 1) ^ (x + 2) ^ (x + 3)) == 0) {
      cout << "0\n4\n";
      cout << x << " " << x + 1 << " " << x + 2 << " " << x + 3;
      exit(0);
    }
  }
  solve3();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> l >> r >> k;
  if (k == 1) solve1();
  if (k == 2) solve2();
  if (k == 3) solve3();
  solve4();
}
