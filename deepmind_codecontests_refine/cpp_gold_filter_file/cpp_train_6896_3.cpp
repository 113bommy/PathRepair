#include <bits/stdc++.h>
using namespace std;
int ask(vector<int> a, vector<int> b) {
  cout << "? " << a.size() << " " << b.size() << "\n";
  for (auto &i : a) cout << i + 1 << " \n"[&i == &a.back()];
  for (auto &i : b) cout << i + 1 << " \n"[&i == &b.back()];
  cout.flush();
  string s;
  cin >> s;
  if (s[0] == 'F') return +1;
  if (s[0] == 'E') return 0;
  if (s[0] == 'S') return -1;
  exit(0);
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
static T randint(T lo, T hi) {
  return uniform_int_distribution<T>(lo, hi)(rng);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int q = 49;
    int p = ask({0}, {1}) == 0;
    if (p)
      for (int i = 9; i > 2; --i) {
        int np = p | (1 << i);
        if (np + 1 < n) {
          int l = p - 1, r = np;
          bool eq = true;
          vector<int> v(r - l + 1);
          assert(v.size() % 2 == 0);
          iota(v.begin(), v.end(), l);
          for (int it = 5 + (i > 6); it--;) {
            --q;
            shuffle(v.begin(), v.end(), rng);
            auto mid = v.begin() + v.size() / 2;
            eq &= ask(vector<int>(v.begin(), mid), vector<int>(mid, v.end())) ==
                  0;
            if (!eq) break;
          }
          if (eq) p = np;
        }
      }
    int f = -1, ans = -1;
    for (int i = 0; i < 8; ++i)
      if (p + i + 1 < n) {
        --q;
        int sg = ask({p + i}, {p + i + 1});
        if (sg == -1) {
          ans = 0;
          break;
        }
        if (sg == 1) {
          f = p + i;
          break;
        }
      }
    assert(f != -1 || ans != -1);
    if (f != -1) {
      bool ok = false;
      while (q--) {
        int f2;
        do {
          f2 = randint(0, n - 1);
        } while (f2 == f);
        ok |= ask({f}, {f2}) == -1;
      }
      ans = !ok * (f + 1);
    }
    cout << "! " << ans + 1 << "\n";
  }
  return 0;
}
