#include <bits/stdc++.h>
using namespace std;
int MaxVal = int(1e6);
long long tree[int(1e6 + 6)][2];
long long read(int idx, int r) {
  long long sum = 0;
  while (idx > 0) {
    sum += tree[idx][r];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, int val, int r) {
  while (idx <= MaxVal) {
    tree[idx][r] += val;
    idx += (idx & -idx);
  }
}
int main() {
  int n, k, a, b, q, D, A, p, Q;
  cin >> n >> k >> a >> b >> q;
  while (q--) {
    cin >> Q;
    if (Q == 1) {
      cin >> D >> A;
      update(D, min(A, b), 0);
      long long p1 = read(D, 0), p2 = read(D - 1, 0);
      if (p1 - p2 > b) update(D, p2 - p1, 0);
      update(D, min(A, a), 1);
      p1 = read(D, 1), p2 = read(D - 1, 1);
      if (p1 - p2 > a) update(D, p2 - p1, 1);
    } else {
      cin >> p;
      cout << read(p - 1, 0) + read(n, 1) - read(p + k - 1, 1) << endl;
    }
  }
}
