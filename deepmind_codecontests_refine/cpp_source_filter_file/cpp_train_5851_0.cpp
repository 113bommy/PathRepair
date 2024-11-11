#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct outputer;
struct outputable {};
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1 &a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1 &a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 100000;
const int C = 26;
struct Input {
  string s;
  bool read() { return !!getline(cin, s) && ((int)(s).size()); }
  void init(const Input &input) { *this = input; }
};
struct Data : Input {
  int64_t ans;
  void write() { cout << ans << endl; }
};
namespace Main {
const int L = 17;
struct Solution : Data {
  vector<int> pos[C];
  int l[N], r[N];
  int cl[N], cr[N];
  int bl[N + 1], br[N + 1];
  int lm[N], rm[N];
  int mxr[N];
  int lk[L][N], rk[L][N];
  int64_t sl[L][N], sr[L][N];
  int cnt[C];
  void solve() {
    for (int i = int(0); i < int(((int)(s).size())); ++i) {
      pos[s[i] - 'a'].emplace_back(i);
    }
    for (int c = int(0); c < int(C); ++c) {
      for (int i = int(0); i < int(((int)(pos[c]).size())); ++i) {
        l[pos[c][i]] = (i == 0) ? 0 : pos[c][i - 1];
        r[pos[c][i]] = (i == ((int)(pos[c]).size()) - 1) ? ((int)(s).size()) - 1
                                                         : pos[c][i + 1];
      }
    }
    for (int i = int(0); i < int(((int)(s).size())); ++i) {
      cl[i] = i;
      cr[i] = i;
    }
    for (int m = int(1); m < int(C + 1); ++m) {
      {
        memset(cnt, 0, sizeof cnt);
        int k = 0;
        int rb = 0;
        int b = -1;
        int dl = 0, dr = 0;
        for (int lb = int(0); lb < int(((int)(s).size())); ++lb) {
          if (lb > b) {
            b = rb;
            dl = bl[b] = ((int)(s).size()) - 1;
            dr = br[b] = 0;
            for (int i = int(b) - 1; i >= int(lb); --i) {
              bl[i] = min(bl[i + 1], l[i]);
              br[i] = min(br[i + 1], r[i]);
            }
          }
          while (rb < ((int)(s).size())) {
            int &x = cnt[s[rb] - 'a'];
            if (k + !x > m) {
              break;
            }
            umn(dl, l[rb]);
            umx(dr, r[rb]);
            rm[rb] = max(br[lb], dr);
            k += !x;
            ++x;
            ++rb;
          }
          mxr[lb] = rb;
          lm[lb] = min(bl[lb], dl);
          int &x = cnt[s[lb] - 'a'];
          --x;
          k -= !x;
        }
      }
      for (int i = int(0); i < int(((int)(s).size())); ++i) {
        lk[0][i] = lm[i];
        rk[0][i] = rm[i];
        sl[0][i] = i;
        sr[0][i] = ((int)(s).size()) - i - 1;
      }
      for (int t = int(0); t < int(L - 1); ++t) {
        for (int i = int(0); i < int(((int)(s).size())); ++i) {
          lk[t + 1][i] = lk[t][lk[t][i]];
          rk[t + 1][i] = rk[t][rk[t][i]];
          sl[t + 1][i] = sl[t][i] + sl[t][lk[t][i]];
          sr[t + 1][i] = sr[t][i] + sr[t][rk[t][i]];
        }
      }
      for (int i = int(0); i < int(((int)(s).size())); ++i) {
        auto up = [&](int t) {
          ans += sl[t][cl[i]];
          ans += sr[t][cr[i]];
          cl[i] = lk[t][cl[i]];
          cr[i] = rk[t][cr[i]];
        };
        for (int t = int(L) - 1; t >= int(0); --t) {
          if (rk[t][cr[i]] < mxr[lk[t][cl[i]]]) {
            up(t);
          }
        }
        if (cr[i] < mxr[cl[i]]) {
          up(0);
        }
      }
    }
  }
  void clear() { *this = Solution(); }
};
}  // namespace Main
Main::Solution sol;
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  sol.read();
  sol.solve();
  sol.write();
  return 0;
}
