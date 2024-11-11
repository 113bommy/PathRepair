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
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 100000;
const int M = 30;
struct Input {
  int n;
  pair<uint32_t, uint32_t> st[N], fn[N];
  bool read() {
    if (!(cin >> n)) {
      return 0;
    }
    for (int i = int(0); i < int(n); ++i) {
      scanf("%u%u%u%u", &st[i].first, &st[i].second, &fn[i].first,
            &fn[i].second);
    }
    return 1;
  }
  void init(const Input& input) { *this = input; }
};
struct Data : Input {
  int ans;
  void write() { cout << ans << endl; }
};
namespace Main {
const int K = 4 * N;
inline int get_last_one(uint32_t x) {
  int res = -1;
  for (int i = int(5) - 1; i >= int(0); --i) {
    if (x & -(1u << (res + (1 << i)))) {
      res += 1 << i;
    }
  }
  return res;
}
inline pair<uint32_t, uint32_t> cut(pair<uint32_t, uint32_t> a, int d) {
  return pair<uint32_t, uint32_t>(a.first & -(1u << (d + 1)),
                                  a.second & -(1u << (d + 1)));
}
inline pair<uint32_t, uint32_t> common(pair<uint32_t, uint32_t> a,
                                       pair<uint32_t, uint32_t> b) {
  int d =
      max(get_last_one(a.first ^ b.first), get_last_one(a.second ^ b.second));
  if (d == -1) {
    return a;
  }
  if ((a.first & (1u << d)) && (b.second & (1u << d))) {
    return cut(a, d);
  }
  if ((a.second & (1u << d)) && (b.first & (1u << d))) {
    return cut(a, d);
  }
  if (a.first & (1 << d)) {
    return cut(b, get_last_one(b.second & ((1 << d) - 1)));
  }
  if (a.second & (1 << d)) {
    return cut(b, get_last_one(b.first & ((1 << d) - 1)));
  }
  if (b.first & (1 << d)) {
    return cut(a, get_last_one(a.second & ((1 << d) - 1)));
  }
  if (b.second & (1 << d)) {
    return cut(a, get_last_one(a.first & ((1 << d) - 1)));
  }
  assert(0);
}
inline uint64_t ord(pair<uint32_t, uint32_t> a) {
  uint64_t res = 0;
  for (int i = int(3) - 1; i >= int(0); --i) {
    if (!a.second) {
      return res + a.first;
    }
    if (a.first & (1u << i)) {
      a.first -= 1u << i;
      res += 1u << i;
      continue;
    }
    if (a.second & (1u << i)) {
      a.second -= 1u << i;
      res += 1ull << (i + i + 1);
      continue;
    }
    res += 1ull << (i + i);
  }
  return res;
}
struct Solution : Data {
  int v_cnt;
  pair<uint32_t, uint32_t> a[K];
  map<pair<uint32_t, uint32_t>, int> num;
  int pr[K];
  int lvl[K];
  int inc[K], dec[K];
  pair<uint64_t, pair<uint32_t, uint32_t> > tmp[K];
  void sort_unique() {
    for (int i = int(0); i < int(v_cnt); ++i) {
      tmp[i] = make_pair(ord(a[i]), a[i]);
    };
    sort(tmp, tmp + v_cnt);
    v_cnt = unique(tmp, tmp + v_cnt) - tmp;
    for (int i = int(0); i < int(v_cnt); ++i) {
      a[i] = tmp[i].second;
    }
  }
  set<int> bounds;
  void flip(int x) {
    if (bounds.count(x)) {
      bounds.erase(x);
    } else {
      bounds.insert(x);
    }
  }
  void solve() {
    for (int i = int(0); i < int(n); ++i) {
      a[v_cnt++] = st[i];
      a[v_cnt++] = fn[i];
    };
    sort_unique();
    ;
    for (int i = int(v_cnt - 1) - 1; i >= int(0); --i) {
      a[v_cnt++] = common(a[i], a[i + 1]);
    };
    sort_unique();
    ;
    for (int i = int(0); i < int(v_cnt); ++i) {
      num[a[i]] = i;
      lvl[i] = a[i].first + a[i].second;
    }
    {
      vector<int> q;
      q.emplace_back(0);
      pr[0] = -1;
      for (int i = int(1); i < int(v_cnt); ++i) {
        while (common(a[q.back()], a[i]) != a[q.back()]) {
          q.pop_back();
          assert(((int)(q).size()));
        }
        pr[i] = q.back();
        q.emplace_back(i);
      }
    }
    memset(inc, 0, sizeof inc);
    memset(dec, 0, sizeof dec);
    for (int i = int(0); i < int(n); ++i) {
      inc[num[st[i]]]++;
      inc[num[fn[i]]]++;
      dec[num[common(st[i], fn[i])]] += 2;
    };
    ;
    ;
    ;
    for (int i = int(v_cnt) - 1; i >= int(0); --i) {
      if (inc[i]) {
        flip(lvl[i]);
        flip(lvl[i] + 1);
      }
      inc[i] -= dec[i];
      if (inc[i]) {
        assert(i);
        flip(lvl[pr[i]] + 1);
        flip(lvl[i]);
        inc[pr[i]] += inc[i];
      }
    }
    bounds.erase(0);
    ans = ((int)(bounds).size());
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
