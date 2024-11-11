#include <bits/stdc++.h>
using namespace std;
vector<int> fst;
int now = 1, k;
void Merge(int l, int r) {
  if (r == l + 1) return;
  if (now == k) return;
  int mid = (l + r) / 2;
  swap(fst[mid - 1], fst[mid]);
  now += 2;
  Merge(l, mid);
  Merge(mid, r);
}
int main() {
  int N, M, i, j, x, ans = 0, lct = 0;
  cin >> N >> k;
  if (k % 2 == 0 || k > N * 2) {
    cout << -1 << endl;
    return 0;
  }
  for (i = 1; i <= N; i++) {
    fst.push_back(i);
  }
  Merge(0, N);
  for (auto v : fst) {
    cout << v << " ";
  }
  cout << endl;
}
