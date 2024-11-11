#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long linf = 1LL << 60;
const int nlim = 20;
vector<int> lucks;
bool used[nlim];
void gen_lucky() {
  for (int len = 1; len <= 9; ++len) {
    for (int mask = 0; mask < (1 << len); ++mask) {
      int x = mask;
      int luck = 0;
      for (int j = 0; j < len; ++j) {
        luck *= 10;
        luck += (x % 2) ? 7 : 4;
        x /= 2;
      }
      lucks.push_back(luck);
    }
  }
  sort((lucks).begin(), (lucks).end());
}
long long fact(int n) {
  long long res = 1;
  for (int i = 2; i < n; ++i) {
    res *= i;
  }
  return res;
}
bool is_luck(int x) {
  for (int i = 0; i < (int)(lucks).size(); ++i) {
    if (lucks[i] == x) {
      return 1;
    }
  }
  return 0;
}
int getn(int n) {
  ++n;
  for (int i = 0; i < nlim; ++i) {
    if (!used[i]) {
      --n;
    }
    if (!n) {
      return i;
    }
  }
  return -1;
}
int main() {
  gen_lucky();
  int n, k;
  cin >> n >> k;
  int st = 1;
  if (n > nlim) {
    st = n - nlim + 1;
  }
  int ans = 0;
  for (int i = 0; i < (int)(lucks).size(); ++i) {
    if (lucks[i] < st) {
      ++ans;
    }
  }
  int pos = 0;
  while (k && st + pos <= n) {
    long long f = fact(n - st - pos + 1);
    long long cnt = k / f;
    if (k % f == 0) {
      --cnt;
    }
    cnt = min((long long)n - st - pos, cnt);
    int x = getn(cnt);
    used[x] = 1;
    if (is_luck(x + st) && is_luck(pos + st)) {
      ++ans;
    }
    ++pos;
    k -= cnt * f;
  }
  if (k > 1) {
    ans = -1;
  }
  cout << ans << "\n";
  return 0;
}
