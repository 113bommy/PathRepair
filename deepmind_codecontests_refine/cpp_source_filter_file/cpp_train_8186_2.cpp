#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    T f = x % y;
    x = y;
    y = f;
  }
  return x;
}
void exgcd(long long a, long long b, long long &d, long long &x, long long &y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long m) {
  long long x, y, d;
  exgcd(a, m, d, x, y);
  return d == 1 ? ((x % m) + m) % m : -1;
}
const int max_len = 200200;
char s[max_len];
int nxt[max_len];
int vid[max_len];
bool solve() {
  int n = strlen(s);
  set<int> last0, last1;
  memset(nxt, -1, sizeof(nxt));
  memset(vid, 0, sizeof(vid));
  int nn = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (!last1.empty()) {
        int x = *last1.rbegin();
        nxt[x] = i;
        last1.erase(x);
        last0.insert(i);
      } else
        nn++;
      last0.insert(i);
    } else {
      if (last0.empty()) {
        return false;
      }
      int x = *last0.rbegin();
      nxt[x] = i;
      last0.erase(x);
      last1.insert(i);
    }
  }
  if (!last1.empty()) return false;
  cout << nn << endl;
  for (int i = 0; i < n; i++) {
    if (!vid[i]) {
      int cnt = 1;
      for (int j = i; j >= 0; j = nxt[j]) {
        cnt++;
        vid[j] = 1;
      }
      cout << cnt;
      for (int j = i; j >= 0; j = nxt[j]) {
        cout << " " << (j + 1);
      }
      cout << endl;
    }
  }
  return true;
}
int main(int argc, char *argv[]) {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> s;
  {
    if (!solve()) {
      cout << -1 << endl;
    };
  }
  return 0;
}
