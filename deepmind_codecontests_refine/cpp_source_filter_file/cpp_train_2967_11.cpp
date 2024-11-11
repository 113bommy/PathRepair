#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long mpow(long long base, long long exp);
long long power(long long a, long long b);
const long long mod = 1e9 + 7;
struct node {
  set<int> s;
};
struct segTree {
  long long arr[2001];
  long long res[8003];
  int operation_arr[4003];
  int NO_OPERATION = 0;
  void init(int x, int lo, int hi) {
    if (lo == hi) {
      res[x] = arr[lo];
      return;
    }
    int mid = (lo + hi) / 2;
    init(2 * x, lo, mid);
    init(2 * x + 1, mid + 1, hi);
    update_point(x);
  }
  int merge_operation(int a, int b) { return (a ^ b); }
  long long merge_results(int a, int b) { return a + b; }
  void modify(int x, int lo, int hi, int l, int r, int op) {
    prop(x, lo, hi);
    if (lo >= l && hi <= r) {
      operation_arr[x] = merge_operation(operation_arr[x], op);
      return;
    }
    int mid = (lo + hi) / 2;
    if (lo > r || hi < l) return;
    modify(2 * x, lo, mid, l, r, op);
    modify(2 * x + 1, mid + 1, hi, l, r, op);
    update(x, lo, hi);
  }
  int get_sum(int x, int lo, int hi, int l, int r) {
    if (lo >= l && hi <= r) return res[x];
    if (lo > r || hi < l) return 0;
    int mid = (lo + hi) / 2;
    return get_sum(2 * x, lo, mid, l, r) +
           get_sum(2 * x + 1, mid + 1, hi, l, r);
  }
  void point_modify(int x, int lo, int hi, int pos, long long val) {
    if (lo == hi) {
      res[x] = val;
      return;
    }
    int mid = (lo + hi) / 2;
    if (pos <= mid)
      point_modify(2 * x, lo, mid, pos, val);
    else
      point_modify(2 * x + 1, mid + 1, hi, pos, val);
    update_point(x);
  }
  long long max_query(int x, int lo, int hi, int l, int r) {
    if (lo >= l && hi <= r) return res[x];
    if (lo > r || hi < l) return -1;
    int mid = (lo + hi) / 2;
    return max(max_query(2 * x, lo, mid, l, r),
               max_query(2 * x + 1, mid + 1, hi, l, r));
  }
  void update_point(int x) { res[x] = max(res[2 * x], res[2 * x + 1]); }
  int query(int x, int lo, int hi, int l, int r) {
    prop(x, lo, hi);
    if (lo >= l && hi <= r) return operate(res[x], operation_arr[x], lo, hi);
    if (lo > r || hi < l) return 0;
    int mid = (lo + hi) / 2;
    return merge_results(query(2 * x, lo, mid, l, r),
                         query(2 * x + 1, mid + 1, hi, l, r));
  }
  int kth_one(int x, int lo, int hi, int k) {
    if (lo == hi) return lo;
    int v1 = res[2 * x];
    int mid = (lo + hi) / 2;
    if (k <= v1)
      return kth_one(2 * x, lo, mid, k);
    else
      return kth_one(2 * x + 1, mid + 1, hi, k - v1);
  }
  void prop(int x, int lo, int hi) {
    if (lo == hi) return;
    int mid = (hi + lo) / 2;
    long long len = mid - lo + 1;
    operation_arr[2 * x] =
        merge_operation(operation_arr[2 * x], operation_arr[x]);
    operation_arr[2 * x + 1] =
        merge_operation(operation_arr[2 * x + 1], operation_arr[x]);
    operation_arr[x] = NO_OPERATION;
    update(x, lo, hi);
  }
  int operate(int val, int operatr, int l, int r) {
    if (operatr == NO_OPERATION) return val;
    int sz = r - l + 1;
    return sz - val;
  }
  void update(int x, int lo, int hi) {
    if (lo == hi) return;
    int mid = (lo + hi) / 2;
    long long len1 = (mid - lo + 1);
    long long len2 = (hi - mid);
    res[x] = merge_results(
        operate(res[2 * x], operation_arr[2 * x], lo, mid),
        operate(res[2 * x + 1], operation_arr[2 * x + 1], mid + 1, hi));
  }
};
struct FenwickTree {
  int arr[100];
  int n;
  void update(int i, int delta) {
    while (i <= n) {
      arr[i] += delta;
      i = i + (i & (-i));
    }
  }
  int sum(int i) {
    if (i == 0) return 0;
    int res = 0;
    while (i > 0) {
      res = res + arr[i];
      i -= (i & (-i));
    }
    return res;
  }
};
struct dsu {
  int par[1001];
  int size_set[1001];
  int get_par(int u) {
    vector<int> temp;
    while (par[u] != u) {
      temp.push_back(u);
      u = par[u];
    }
    for (int i : temp) par[i] = u;
    return u;
  }
  void union_set(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if (a == b) return;
    if (size_set[a] < size_set[b]) {
      int temp = a;
      a = b;
      b = temp;
    }
    par[b] = a;
    size_set[a] += size_set[b];
  }
};
int check(string s1, string s2) {
  int n1 = s1.size();
  int n2 = s2.size();
  s1 = '$' + s1;
  s2 = '$' + s2;
  int dp[n1 + 1][n2 + 1];
  for (int j = 0; j <= n2; j++) dp[0][j] = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= n1; i++) {
    dp[i][0] = 0;
  }
  int i1 = 1;
  while (i1 <= n1 && s1[i1] == '*') {
    dp[i1][0] = 1;
    i1++;
  }
  int sum[n2 + 1];
  int s = 0;
  for (int i = 0; i <= n2; i++) s = s + dp[0][i], sum[i] = s;
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      char c1 = s1[i];
      char c2 = s2[j];
      if (c1 == '*') {
        if (sum[j] > 0)
          dp[i][j] = 1;
        else
          dp[i][j] = 0;
      } else if (c1 == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        if (c1 != c2)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j - 1];
      }
    }
    s = 0;
    for (int j = 0; j <= n2; j++) {
      s += dp[i][j];
      sum[j] = s;
    }
  }
  return dp[n1][n2];
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pw1[21];
long long pw2[21];
long long m1 = 1e9 + 7;
long long m2 = 1e9 + 9;
long long base = 30;
pair<long long, long long> string_hash(string s) {
  long long res1 = 0, res2 = 0;
  for (int i = 0; i < s.size(); i++) {
    int v = s[i] - 'a';
    res1 = (res1 + v * pw1[i]) % m1;
    res2 = (res2 + v * pw2[i]) % m2;
  }
  return make_pair(res1, res2);
}
bool isOverflow(long long a, long long b) {
  if (a == 0 || b == 0) return false;
  if (a <= LLONG_MAX / b)
    return false;
  else
    return true;
}
bool isOverflow_add(long long a, long long b) {
  long long res = a + b;
  if (res - a == b && res - b == a) return 0;
  return 1;
}
int seive[10000000 + 1];
int cntp[10000000 + 1];
int cntpal[10000000 + 1];
int count_primes(int n) {
  memset(seive, 0, sizeof(seive));
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (seive[i] == 0) cnt++;
    cntp[i] = cnt;
    if (seive[i] != 0) continue;
    for (int j = i; j <= n; j += i) {
      seive[j] = 1;
    }
  }
  return cnt;
}
bool is_pal(int n) {
  vector<int> temp;
  while (n > 0) {
    int d = n % 10;
    n /= 10;
    temp.push_back(d);
  }
  int i = 0, j = temp.size() - 1;
  while (i <= j) {
    if (temp[i] != temp[j]) return 0;
    i++, j--;
  }
  return 1;
}
void count_palindromic() {
  int cnt = 0;
  int n = 2000000;
  for (int i = 1; i <= n; i++) {
    if (is_pal(i)) cnt++;
    cntpal[i] = cnt;
  }
}
void solve() {
  long long p, q;
  cin >> p >> q;
  count_primes(10000000);
  count_palindromic();
  int res = -1;
  for (int i = 2; i <= 2000000; i++) {
    long long v1 = cntp[i], v2 = cntpal[i];
    if (q * v1 <= p * v2) {
      res = i;
    }
  }
  if (res != -1)
    cout << res << "\n";
  else
    cout << "Palindromic tree is better than splay tree"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
long long mpow(long long base, long long exp) {
  base %= mod;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 0) {
      b /= 2;
      if (isOverflow(a, a)) return LLONG_MAX;
      a = a * a;
    } else {
      if (isOverflow(res, a)) return LLONG_MAX;
      res = res * a;
      b--;
    }
  }
  return res;
}
