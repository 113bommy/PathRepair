#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const long long LINF = 2e18;
void inv(bool e);
template <typename T>
T sign(T a);
template <typename T>
void die(T &a);
template <typename T>
void umax(T &a, T b);
template <typename T>
void umin(T &a, T b);
bool brute, alter;
int cnt_tests = 1;
int n;
long long x, y;
void inp() { cin >> n >> x >> y; }
long long ask(vector<int> &val) {
  cout << "? " << ((int)(val).size()) << ' ';
  for (auto x : val) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
  cout << flush;
  long long ans;
  cin >> ans;
  cout << flush;
  return ans;
}
const int LOG = 9;
bool good(long long val) {
  if (val == y || val == (y ^ x)) {
    return true;
  }
  return false;
}
void solve() {
  vector<int> cur;
  bool fnd = false;
  int bit = -1;
  long long p1 = 0, p2 = 0;
  for (int i = 0; i < LOG; i++) {
    cur.clear();
    for (int j = 0; j < n; j++) {
      if ((j >> i) & 1) {
        if (!fnd) {
          cur.push_back(j);
        } else {
          if ((j >> bit) & 1) {
            cur.push_back(j);
          }
        }
      }
    }
    if (cur.empty()) {
      break;
    }
    long long res = ask(cur);
    if (!fnd) {
      if (good(res)) {
        fnd = true;
        bit = i;
        p1 |= (1 << i);
      }
    } else {
      if (good(res)) {
        p1 |= (1 << i);
      }
    }
  }
  cerr << p1 << " f2\n";
  for (int i = 0; i < bit; i++) {
    cur.clear();
    for (int j = 0; j < n; j++) {
      if ((j >> bit) & 1) {
        if ((j >> i) & 1) {
          cur.push_back(j);
        }
      }
    }
    if (cur.empty()) {
      break;
    }
    long long res = ask(cur);
    if (good(res)) {
      p1 |= (1 << i);
      p2 |= (1 << i);
    }
  }
  for (int i = bit + 1; i < LOG; i++) {
    cur.clear();
    for (int j = 0; j < n; j++) {
      if (((j >> bit) & 1) == 0) {
        if ((j >> i) & 1) {
          cur.push_back(j);
        }
      }
    }
    if (cur.empty()) {
      break;
    }
    long long res = ask(cur);
    if (good(res)) {
      p2 |= (1 << i);
    }
  }
  if (p1 > p2) {
    swap(p1, p2);
  }
  cout << "! " << p1 + 1 << ' ' << p2 + 1;
  cout << flush;
}
void stress() {}
void naive() {}
void run();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (0) {
    freopen("substrcmp.in", "r", stdin);
    freopen("substrcmp.out", "w", stdout);
  }
  srand(time(0));
  brute = false;
  for (int i = 0; (i < cnt_tests); i++) {
    run();
  }
  cerr << '\n' << "Time: " << clock() / 1000.0 << " ms";
  return 0;
}
void run() {
  if (!brute) {
    inp();
  } else {
    stress();
  }
  solve();
  cout << '\n';
}
template <typename T>
void die(T &a) {
  cout << a;
  exit(0);
}
template <typename T>
T sign(T a) {
  if (a == 0) return 0;
  if (a < 0) return -1;
  return 1;
}
template <typename T>
void umax(T &a, T b) {
  if (b > a) a = b;
}
template <typename T>
void umin(T &a, T b) {
  if (b < a) a = b;
}
void inv(bool e) {
  if (!e) {
    vector<int> a;
    a[-1] += 1;
  }
}
