#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long poww(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = poww(a, b / 2);
  return (b & 1 ? a * tmp * tmp : tmp * tmp);
}
string itos(long long i) {
  string s = "";
  while (i) {
    s += char(i % 10 + '0');
    i /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long stoi(string &s) {
  long long tot = 0;
  for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10) {
    tot += j * (s[i] + '0');
  }
  return tot;
}
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
using namespace std;
void tt() { freopen("test.txt", "r", stdin); }
const int MAX = 1e6 + 10;
int n, m, seed, vmax;
int a[MAX];
int rnd() {
  int ret = seed;
  seed = (1ll * seed * 7 + 13) % (1000 * 1000 * 1000 + 7);
  return ret;
  ;
}
int pw(int num, int power, int MOD) {
  if (power == 0) {
    return 1 % MOD;
  }
  int x = 1ll * pw(num, power / 2, MOD) % MOD;
  int ans = 1ll * x % MOD * x % MOD * ((power & 1) ? num : 1) % MOD;
  return ans % MOD;
}
long long Power(long long Base, long long Exp, long long Mod) {
  Base %= Mod;
  long long res = 1;
  do {
    if (Exp & 1) (res *= Base) %= Mod;
    (Base *= Base) %= Mod;
  } while (Exp >>= 1);
  return res;
}
map<int, long long> s;
int main() {
  cin >> n >> m >> seed >> vmax;
  for (int i = 1; i <= n; i++) a[i] = (rnd() % vmax) + 1;
  for (int i = 1; i <= n; i++) s.insert({i, a[i]});
  for (int i = 1; i <= m; i++) {
    int x, y;
    int op = (rnd() % 4) + 1;
    int l = (rnd() % n) + 1;
    int r = (rnd() % n) + 1;
    if (l > r) {
      swap(l, r);
    }
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else
      x = (rnd() % vmax) + 1;
    if (op == 4) y = (rnd() % vmax) + 1;
    auto itl = s.upper_bound(l);
    --itl;
    if (itl->first != l) {
      s[l] = itl->second;
      ++itl;
    }
    auto itr = s.upper_bound(r + 1);
    --itr;
    if (itr->first != r + 1) {
      s[r + 1] = itr->second;
      ++itr;
    }
    if (op == 1) {
      while (itl != itr) {
        itl->second += x;
        itl++;
      }
    } else if (op == 2) {
      while (itl != itr) {
        s.erase(itl++);
      }
      s[l] = x;
    } else if (op == 3) {
      vector<pair<long long, int> > v;
      while (itr != itl) {
        int a = itr->first;
        itr--;
        int b = itr->first;
        v.push_back({itr->second, a - b});
      }
      int res = 0, cnt = 0;
      sort(v.begin(), v.end());
      for (auto t : v) {
        cnt += t.second;
        if (cnt >= x) {
          res = t.first;
          break;
        }
      }
      cout << res << '\n';
    } else if (op == 4) {
      vector<pair<int, int> > v;
      long long res = 0;
      for (int ub; itl != itr;)
        ub = (itr--)->first,
        (res += Power(itr->second, x, y) * (ub - itr->first)) %= y;
      cout << res << '\n';
    }
  }
  return 0;
}
