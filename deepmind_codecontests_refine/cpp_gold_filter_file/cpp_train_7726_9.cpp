#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 70;
int bit[N];
long long n;
int m;
int find_idx(int x) {
  for (int i = 0; i < 32; ++i) {
    if (x & (1 << i)) return i;
  }
  return 0;
}
void no() { cout << "-1" << endl; }
void HalfDead() {
  memset(bit, 0, sizeof bit);
  int x;
  long long sum = 0;
  cin >> n >> m;
  for (int i = 0; i < (int)m; ++i) {
    cin >> x;
    int idx = find_idx(x);
    bit[idx]++;
    sum += x;
  }
  if (sum < n) {
    no();
    return;
  }
  int move = 0;
  for (long long i = 0; i < 64; ++i) {
    if (!(n & (1LL << i))) {
      bit[i + 1] += (bit[i] / 2);
      continue;
    }
    if (bit[i]) {
      bit[i]--;
      bit[i + 1] += (bit[i]) / 2;
    } else {
      int j = i + 1;
      while (bit[j] == 0 and j < 64) j++;
      bit[j]--;
      while (j > i) {
        bit[j - 1] += 1;
        move++;
        j--;
      }
    }
  }
  cout << move << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    HalfDead();
  }
  return 0;
}
