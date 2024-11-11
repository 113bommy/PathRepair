#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int n;
int a[N];
void scan() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}
vector<int> bases;
bool is_base(int x) {
  if (x > N / 3) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    if (x != a[i] && x % a[i] == 0) {
      return false;
    }
  }
  return true;
}
void build_bases() {
  for (int i = 0; i < n; ++i) {
    if (is_base(a[i])) {
      bases.push_back(a[i]);
    }
  }
}
const int MOD = 1e9 + 7;
int sum(int x, int y) { return x + y < MOD ? x + y : x + y - MOD; }
int add(int &x, int y) { return x = sum(x, y); }
int mul(int x, int y) { return x * 1LL * y % MOD; }
int fact(int k) { return k ? mul(k, fact(k - 1)) : 1; }
int bp(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = mul(res, x);
    }
    x = mul(x, x);
    k >>= 1;
  }
  return res;
}
int inv(int x) { return bp(x, MOD - 2); }
int kek[N + 7][N + 7];
void build_kek() {
  for (int i = 0; i < N + 7; ++i) {
    kek[i][0] = 1;
    for (int j = 1; j < N + 7; ++j) {
      for (int k = 1; k <= i; ++k) {
        kek[i][j] = sum(kek[i][j], kek[k][j - 1]);
      }
    }
  }
}
int b_mask(int x) {
  int res = 0;
  for (int i = 0; i < bases.size(); ++i) {
    res |= (x % bases[i] == 0) << i;
  }
  return res;
}
bool gd[N];
void build_gd() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (!is_base(a[i]) && !is_base(a[j]) && b_mask(a[i]) & b_mask(a[j])) {
        gd[i] = gd[j] = true;
      }
    }
  }
}
int dp[1 << 12 + 1][N + 1];
void build_dp() {
  for (int mask = (1 << bases.size()) - 1; mask >= 0; --mask) {
    for (int k = 0; k <= N; ++k) {
      vector<int> cur;
      for (int i = 0; i < n; ++i) {
        if (!is_base(a[i]) && (b_mask(a[i]) & ~mask) && gd[i]) {
          cur.push_back(a[i]);
        }
      }
      if (cur.size() == 0) {
        dp[mask][k] = !k;
      } else {
        vector<int> good_nxt;
        for (int x : cur) {
          if (b_mask(x) & mask) {
            good_nxt.push_back(x);
          }
        }
        int flag = 0;
        if (good_nxt.empty()) {
          good_nxt = vector<int>(cur);
          flag = 1;
        }
        for (int i = 0; i < good_nxt.size(); ++i) {
          int cnt = 0;
          bool f = false;
          for (int j = 0; j < cur.size(); ++j) {
            cnt += ((b_mask(cur[j]) | mask | b_mask(good_nxt[i])) ==
                    (mask | b_mask(good_nxt[i])));
          }
          if (k - cnt + flag >= 0) {
            add(dp[mask][k],
                mul(mul(fact(cnt - 1), kek[k - cnt + flag + 1][cnt - 1]),
                    dp[mask | b_mask(good_nxt[i])][k - cnt + flag]));
          }
        }
      }
    }
  }
}
void gen_test() {
  n = 7;
  set<int> f;
  for (int i = 0; i < n; ++i) {
    do {
      a[i] = rand() % 15 + 1;
    } while (f.find(a[i]) != f.end());
    f.insert(a[i]);
  }
}
void print_test() {
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
int color[N];
int cur_color = 1;
void dfs(int x) {
  color[x] = cur_color;
  for (int i = 0; i < n; ++i) {
    if (color[a[i]] == 0 && (b_mask(a[i]) & b_mask(x))) {
      dfs(a[i]);
    }
  }
}
int get_ans() {
  for (int i = 0; i < n; ++i) {
    if (color[a[i]] == 0) {
      dfs(a[i]);
      ++cur_color;
    }
  }
  vector<pair<int, int>> arr(cur_color, {0, 0});
  for (int i = 0; i < n; ++i) {
    arr[color[a[i]]].first |= b_mask(a[i]);
    ++arr[color[a[i]]].second;
  }
  int res = 1;
  int k = 0;
  for (int i = 1; i < arr.size(); ++i) {
    int x = N;
    int mask = (1 << bases.size()) - 1 ^ arr[i].first;
    while (!dp[mask][x]) {
      --x;
    }
    res = mul(res, mul(dp[mask][x], bp(k + 1, x)));
    k += x;
  }
  return res;
}
void solve() {
  build_bases();
  build_gd();
  build_dp();
}
bool ok(int k, int mask) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && j != k && k != i && (~mask >> i & 1) && (~mask >> j & 1) &&
          a[k] % a[i] == 0 && a[j] % a[i] == 0) {
        return true;
      }
    }
  }
  return false;
}
int ans = 0, bcnt = 0;
void rec(int mask, int cnt) {
  if (cnt > bcnt) {
    ans = 1;
    bcnt = cnt;
  } else if (cnt == bcnt) {
    add(ans, 1);
  }
  for (int k = 0; k < n; ++k) {
    if ((~mask >> k & 1) && ok(k, mask)) {
      rec(1 << k | mask, cnt + 1);
    }
  }
}
int stupid_solve() {
  rec(0, 0);
  return ans;
}
void clear_all() {
  bases.clear();
  for (int i = 0; i < (1 << 12); ++i) {
    for (int x = 0; x <= N; ++x) {
      dp[i][x] = 0;
    }
  }
  ans = 0, bcnt = 0;
  fill(gd, gd + N, 0);
  cur_color = 1;
  fill(color, color + N + 1, 0);
}
void stresstest() {
  int n_test = 1;
  while (true) {
    cout << "TEST #" << n_test++ << '\n';
    gen_test();
    print_test();
    solve();
    int r_ans = stupid_solve();
    int m_ans = get_ans();
    if (r_ans != get_ans()) {
      cout << "FAIL\n";
      cout << "RIGHT ANS: " << r_ans << '\n';
      cout << "MY ANS: " << m_ans << '\n';
      system("pause");
    } else {
      cout << "SUCCES\n";
    }
    clear_all();
  }
}
int main() {
  build_kek();
  scan();
  solve();
  cout << get_ans() << '\n';
  return 0;
}
