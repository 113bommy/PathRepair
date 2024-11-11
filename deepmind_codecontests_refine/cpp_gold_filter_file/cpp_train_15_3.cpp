#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long fen[N];
void modify(int x, long long v) {
  while (x < N) {
    fen[x] += v;
    x |= x + 1;
  }
}
long long get(int x) {
  long long r = 0;
  while (x >= 0) {
    r += fen[x];
    x = (x & (x + 1)) - 1;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> s(n);
  for (int(i) = 0; (i) < (int)(n); ++(i)) cin >> s[i];
  for (int(i) = 0; (i) < (int)(n); ++(i)) modify(i, i + 1);
  vector<int> a(n);
  for (int i = n - 1; i >= 0; i--) {
    int low = 0, high = n - 1;
    while (low < high) {
      int mid = (low + high) >> 1;
      if (get(mid) > s[i]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    a[i] = low + 1;
    modify(low, -low - 1);
  }
  for (int(i) = 0; (i) < (int)(n); ++(i)) cout << a[i] << ' ';
  cout << '\n';
}
