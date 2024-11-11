#include <bits/stdc++.h>
using namespace std;
inline void IN(void) { return; }
template <typename First, typename... Rest>
void IN(First &first, Rest &...rest) {
  cin >> first;
  IN(rest...);
  return;
}
inline void OUT(void) {
  cout << "\n";
  return;
}
template <typename First, typename... Rest>
void OUT(First first, Rest... rest) {
  cout << first << " ";
  OUT(rest...);
  return;
}
template <typename T>
void vec_print(vector<T> VEC) {
  for (long long i = (long long)0; i < (long long)VEC.size(); ++i) {
    cout << VEC[i] << " ";
  }
  cout << "\n";
};
template <typename T>
void mat_print(vector<vector<T>> MAT) {
  for (long long i = (long long)0; i < (long long)MAT.size(); ++i) {
    for (long long j = (long long)0; j < (long long)MAT[i].size(); ++j) {
      cout << MAT[i][j] << " ";
    }
    cout << "\n";
  }
};
template <typename CLASS1, typename CLASS2>
class HOGE {
 public:
  CLASS1 key;
  CLASS2 value;
  HOGE(void) { return; };
  HOGE(CLASS1 key, CLASS2 value) {
    this->key = key;
    this->value = value;
  };
  ~HOGE(void) { return; };
  void print(void) {
    cout << "key : " << key << ", value : " << value << "\n";
    return;
  };
  bool operator==(const HOGE &obj) { return (this->value == obj.value); };
  bool operator<(const HOGE &obj) { return (this->value < obj.value); };
  bool operator>(const HOGE &obj) { return (this->value > obj.value); };
};
template <typename CLASS1, typename CLASS2>
bool operator==(const HOGE<CLASS1, CLASS2> &hoge1,
                const HOGE<CLASS1, CLASS2> &hoge2) {
  return hoge1.value == hoge2.value;
};
template <typename CLASS1, typename CLASS2>
bool operator<(const HOGE<CLASS1, CLASS2> &hoge1,
               const HOGE<CLASS1, CLASS2> &hoge2) {
  return hoge1.value < hoge2.value;
};
template <typename CLASS1, typename CLASS2>
bool operator>(const HOGE<CLASS1, CLASS2> &hoge1,
               const HOGE<CLASS1, CLASS2> &hoge2) {
  return hoge1.value > hoge2.value;
};
constexpr int INF = (1 << 30);
constexpr long long INFLL = 1LL << 62;
constexpr long double EPS = 1e-12;
constexpr long long MOD = (long long)(998244353);
vector<long long> inv(10000);
void initialize_inv(void) {
  inv[1] = 1;
  for (int i = 2; i < 10000; ++i) {
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
  }
  return;
}
vector<vector<long long>> dp_all(2557, vector<long long>(2557, 0));
set<pair<long long, long long>> st_all;
void calc_all(long long wp, long long wm, long long m) {
  vector<map<pair<long long, long long>, long long>> vmp(m + 1);
  vmp[0][make_pair(wp, wm)] += 1;
  for (long long M = (long long)0; M < (long long)m; ++M) {
    for (auto itr : vmp[M]) {
      long long wp_tmp = itr.first.first;
      long long wm_tmp = itr.first.second;
      long long dp_tmp = itr.second;
      long long inv_sum = inv[wp_tmp + wm_tmp];
      vmp[M + 1][make_pair(wp_tmp + 1, wm_tmp)] +=
          (dp_tmp * (wp_tmp * inv_sum) % MOD) % MOD;
      vmp[M + 1][make_pair(wp_tmp + 1, wm_tmp)] %= MOD;
      if (wm_tmp - 1 >= 0) {
        vmp[M + 1][make_pair(wp_tmp, wm_tmp - 1)] +=
            (dp_tmp * (wm_tmp * inv_sum) % MOD) % MOD;
        vmp[M + 1][make_pair(wp_tmp, wm_tmp - 1)] %= MOD;
      }
    }
  }
  for (auto itr : vmp[m]) {
    long long wp_tmp = itr.first.first;
    long long wm_tmp = itr.first.second;
    dp_all[wp_tmp][wm_tmp] = itr.second;
    pair<long long, long long> st_tmp = make_pair(wp_tmp, wm_tmp);
    st_all.emplace(st_tmp);
  }
  return;
}
long long calc_p(long long w, long long wp, long long m) {
  vector<vector<long long>> dp(107, vector<long long>(3000, 0));
  dp[w][wp] = 1;
  set<pair<long long, long long>> st;
  pair<long long, long long> st_tmp = make_pair(w, wp);
  st.emplace(st_tmp);
  for (long long M = (long long)0; M < (long long)m; ++M) {
    set<pair<long long, long long>> st_new;
    for (auto itr : st) {
      long long w_tmp = itr.first;
      long long wp_tmp = itr.second;
      long long inv_sum = inv[w_tmp + wp_tmp];
      dp[w_tmp + 1][wp_tmp] +=
          (dp[w_tmp][wp_tmp] * ((w_tmp * inv_sum) % MOD)) % MOD;
      dp[w_tmp + 1][wp_tmp] %= MOD;
      pair<long long, long long> st_tmp = make_pair(w_tmp + 1, wp_tmp);
      st_new.emplace(st_tmp);
      dp[w_tmp][wp_tmp + 1] +=
          (dp[w_tmp][wp_tmp] * ((wp_tmp * inv_sum) % MOD)) % MOD;
      dp[w_tmp][wp_tmp + 1] %= MOD;
      st_tmp = make_pair(w_tmp, wp_tmp + 1);
      st_new.emplace(st_tmp);
    }
    st = st_new;
  }
  long long ans = 0;
  for (auto itr : st_all) {
    long long wp_tmp = itr.first;
    long long wm_tmp = itr.second;
    long long k = wp_tmp - w - wp;
    long long count = 0;
    for (int i = 0; i <= k && wp_tmp - w - i >= 0; ++i) {
      ans += ((w + i) *
              ((dp_all[wp_tmp][wm_tmp] * dp[w + i][wp_tmp - w - i]) % MOD)) %
             MOD;
      ans %= MOD;
      count++;
    }
  }
  return ans;
}
long long calc_m(long long w, long long wm, long long m) {
  vector<vector<long long>> dp(107, vector<long long>(3000, 0));
  dp[w][wm] = 1;
  set<pair<long long, long long>> st;
  pair<long long, long long> st_tmp = make_pair(w, wm);
  st.emplace(st_tmp);
  for (long long M = (long long)0; M < (long long)m; ++M) {
    set<pair<long long, long long>> st_new;
    for (auto itr : st) {
      long long w_tmp = itr.first;
      long long wm_tmp = itr.second;
      long long inv_sum = inv[w_tmp + wm_tmp];
      if (w_tmp - 1 >= 0) {
        dp[w_tmp - 1][wm_tmp] +=
            (dp[w_tmp][wm_tmp] * ((w_tmp * inv_sum) % MOD)) % MOD;
        dp[w_tmp - 1][wm_tmp] %= MOD;
        pair<long long, long long> st_tmp = make_pair(w_tmp - 1, wm_tmp);
        st_new.emplace(st_tmp);
      }
      if (wm_tmp - 1 >= 0) {
        dp[w_tmp][wm_tmp - 1] +=
            (dp[w_tmp][wm_tmp] * ((wm_tmp * inv_sum) % MOD)) % MOD;
        dp[w_tmp][wm_tmp - 1] %= MOD;
        st_tmp = make_pair(w_tmp, wm_tmp - 1);
        st_new.emplace(st_tmp);
      }
    }
    st = st_new;
  }
  long long ans = 0;
  for (auto itr : st_all) {
    long long wp_tmp = itr.first;
    long long wm_tmp = itr.second;
    long long k = w + wm - wm_tmp;
    for (int i = 0; i <= k && w - i > 0; ++i) {
      if (wm_tmp - w + i >= 0) {
        ans += ((w - i) *
                ((dp_all[wp_tmp][wm_tmp] * dp[w - i][wm_tmp - w + i]) % MOD)) %
               MOD;
        ans %= MOD;
      }
    }
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  initialize_inv();
  long long n, m;
  IN(n, m);
  vector<long long> a(n);
  for (long long i = (long long)0; i < (long long)n; ++i) IN(a[i]);
  vector<long long> w(n);
  long long wp_sum = 0, wm_sum = 0;
  for (long long i = (long long)0; i < (long long)n; ++i) {
    IN(w[i]);
    if (a[i] == 0)
      wm_sum += w[i];
    else
      wp_sum += w[i];
  }
  calc_all(wp_sum, wm_sum, m);
  for (long long i = (long long)0; i < (long long)n; ++i) {
    if (a[i] == 0) {
      OUT(calc_m(w[i], wm_sum - w[i], m));
    } else {
      OUT(calc_p(w[i], wp_sum - w[i], m));
    }
  }
  return 0;
}
