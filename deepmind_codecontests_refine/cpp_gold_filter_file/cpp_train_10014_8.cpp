#include <bits/stdc++.h>
using namespace std;
const long double PI = 2 * acos(0.0);
void yes() { cout << "YES\n"; }
void no() {
  cout << "NO\n";
  cout << -1 << "\n";
  exit(0);
}
long long m(long long a) { return (a + 1000000007) % 1000000007; }
long long cel(long long x1, long long y1) {
  ;
  if ((x1 % y1) == 0) return x1 / y1;
  return x1 / y1 + 1;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long d = power(a, b / 2);
  d = m(d * d);
  if (b & 1) d = m(d * a);
  return d;
}
long long seg[800005], a[200005];
void build(long long pos, long long ss, long long second) {
  if (ss == second) {
    seg[pos] = a[ss];
    return;
  }
  long long mid = (ss + second) / 2;
  build(2 * pos + 1, ss, mid);
  build(2 * pos + 2, mid + 1, second);
  seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);
}
long long query(long long pos, long long ss, long long second, long long l,
                long long r) {
  if (l > second || r < ss) return 1e10;
  if (ss >= l && second <= r) return seg[pos];
  long long mid = (ss + second) / 2;
  long long max1 = query(2 * pos + 1, ss, mid, l, r);
  long long max2 = query(2 * pos + 2, mid + 1, second, l, r);
  return min(max1, max2);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> arr;
  vector<pair<long long, long long>> vec;
  for (long long i = 0; i < n; i++) {
    long long val;
    cin >> val;
    arr.push_back(val);
    vec.push_back({val, i});
  }
  sort(vec.rbegin(), vec.rend());
  for (long long i = 0; i < n; i++) {
    a[i] = arr[i];
    a[i + n] = arr[i];
  }
  stack<long long> st;
  vector<long long> gt(2 * n, 0);
  long long mxx = *(max_element(arr.begin(), arr.end()));
  for (long long i = n - 1; i >= 0; i--) {
    if (arr[i] == mxx) {
      gt[i] = vec[0].second;
    }
  }
  for (long long i = 0; i < 2 * n; i++) {
    while (!st.empty() && a[st.top()] < a[i]) {
      gt[(st.top())] = i;
      st.pop();
    }
    st.push(i);
  }
  build(0, 0, 2 * n - 1);
  vector<long long> ans(n, 0);
  long long mind = vec[0].second;
  ans[mind] = 1;
  for (long long i = mind + 1; i < (mind + n); i++) {
    if (a[i] < ((a[mind] + 1) / 2)) break;
    ans[mind]++;
  }
  if (ans[mind] == n) ans[mind] = -1;
  for (long long i = 1; i < n; i++) {
    long long ind = vec[i].second;
    long long indd = gt[ind];
    long long l = ind, f = indd, lmax = ind;
    long long val = vec[i].first;
    val = (val + 1) / 2;
    while (l <= f) {
      long long mid = (l + f) / 2;
      long long mn = query(0, 0, 2 * n - 1, ind, mid);
      if (mn < val) {
        f = mid - 1;
      } else {
        l = mid + 1;
        lmax = mid;
      }
    }
    ans[ind] = lmax - ind + 1;
    if (lmax == indd) {
      ans[ind]--;
      if (ans[(indd) % n] == -1)
        ans[ind] = -1;
      else
        ans[ind] += ans[(indd) % n];
    }
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
