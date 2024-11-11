#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int aib[N];
void update(int poz, int val) {
  for (int i = poz; i < N; i += i & (-i)) aib[i] += val;
}
int query(int poz) {
  int rsp = 0;
  for (int i = poz; i > 0; i -= i & (-i)) rsp += aib[i];
  return rsp;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    update(x, 1);
  }
  for (int i = 1; i <= q; i++) {
    int k;
    cin >> k;
    if (k > 0) {
      update(k, 1);
    } else {
      int pas = 0;
      k = -k;
      for (int p2 = 17; p2 > 0; p2 /= 2) {
        if (pas + p2 <= n && aib[pas + p2] < k) {
          pas += p2;
          k -= aib[pas];
        }
      }
      pas++;
      update(pas, -1);
    }
  }
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    if (query(i) - query(i - 1) > 0) {
      ok = true;
      cout << i << "\n";
      return 0;
    }
  }
  cout << "0";
  return 0;
}
