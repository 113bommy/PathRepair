#include <bits/stdc++.h>
using namespace std;
using namespace std;
int nxt() {
  int x;
  cin >> x;
  return x;
}
const long long INF = int(1e9) + 99;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
const int N = int(2e5) + 99;
vector<int> plist;
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prime[p]) plist.push_back(p);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
int mergeSort(int arr[], int array_size) {
  int temp[array_size];
  return _mergeSort(arr, temp, 0, array_size - 1);
}
int _mergeSort(int arr[], int temp[], int left, int right) {
  int mid, inv_count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    inv_count += _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid + 1, right);
    inv_count += merge(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}
int merge(int arr[], int temp[], int left, int mid, int right) {
  int i, j, k;
  int inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1) temp[k++] = arr[i++];
  while (j <= right) temp[k++] = arr[j++];
  for (i = left; i <= right; i++) arr[i] = temp[i];
  return inv_count;
}
long long binomialCoeff(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
int MAXN = 8e5;
pair<int, int> t[800000];
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return a;
  if (b.first < a.first) return b;
  return make_pair(a.first, ((a.second > b.second) ? b.second : a.second));
}
void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = make_pair(a[tl], tl);
  } else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
  }
}
pair<int, int> get_first(int v, int lv, int rv, int l, int r, int x) {
  if (lv > r || rv < l) return make_pair(INF, -1);
  if (l <= lv && rv <= r) {
    if (t[v].first >= x) return make_pair(INF, -1);
    while (lv != rv) {
      int mid = lv + (rv - lv) / 2;
      if (t[2 * v].first < x) {
        v = 2 * v;
        rv = mid;
      } else {
        v = 2 * v + 1;
        lv = mid + 1;
      }
    }
    return make_pair(x - 1, lv);
  }
  int mid = lv + (rv - lv) / 2;
  pair<int, int> rs = get_first(2 * v, lv, mid, l, r, x);
  if (rs.second != -1) return rs;
  return get_first(2 * v + 1, mid + 1, rv, l, r, x);
}
void solve() {
  long long l, r, g, x, y, m, n, ans1 = 1e9 + 7, ans13 = 0, ans2 = 0, ans3 = 0,
                                 value, ans4 = 0, flag1 = 0, ans5 = 0,
                                 ans6 = -1e18, ans = 0, k = 0, d;
  cin >> n >> m;
  set<int> s;
  vector<int> v(n), v1(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  ;
  for (int i = n - 1; i >= 0; i--) {
    s.insert(v[i]);
    v1[i] = s.size();
  }
  for (long long i = 0; i < m; i++) {
    cin >> x;
    cout << v1[x - 1] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  SieveOfEratosthenes(100000);
  long long t = 1;
  while (t--) {
    solve();
    cout << "\n";
    cerr << t << " ";
  }
  return 0;
}
