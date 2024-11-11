#include <bits/stdc++.h>
using namespace std;
template <typename T>
void input(vector<T> &arr, long long int n) {
  T temp;
  for (long long int i = 0; i < n; i++) cin >> temp, arr.push_back(temp);
}
template <typename T>
void output(vector<T> arr) {
  for (auto x : arr) cout << x << " ";
  cout << endl;
}
template <typename T>
void input_set(set<T> &arr, long long int n) {
  T temp;
  for (long long int i = 0; i < n; i++) cin >> temp, arr.insert(temp);
}
long long int mul(long long int a, long long int b) {
  return (a % 1000000007 * b % 1000000007) % 1000000007;
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    ;
    b >>= 1;
  }
  return ans;
}
vector<long long int> a, b;
bool check() {
  map<long long int, long long int> make_pair;
  for (int i = 0; i < a.size(); i++) make_pair[a[i]] = i;
  int ma = -1;
  for (int i = 0; i < b.size(); i++) {
    if (make_pair[b[i]] < ma) return false;
    ma = make_pair[b[i]];
  }
  return true;
}
void solve() {
  int n, m;
  cin >> n >> m;
  long long int x, k, y;
  cin >> x >> k >> y;
  a.clear(), b.clear();
  input(a, n);
  input(b, m);
  bool possible = check();
  if (!possible) {
    cout << -1 << endl;
    return;
  }
  map<long long int, long long int> make_pair;
  for (int i = 0; i < a.size(); i++) make_pair[a[i]] = i;
  vector<bool> marked(n, true);
  for (auto x : b) marked[make_pair[x]] = false;
  long long int ans = 0;
  int i = 0;
  while (i < n) {
    int j = i;
    long long int ma = -1;
    if (!marked[i]) {
      ++i;
      continue;
    }
    while (j < n and marked[j]) {
      ma = max(ma, a[j]);
      ++j;
    }
    int cnt = j - i;
    long long int left = (i == 0) ? -1 : a[i - 1];
    long long int right = (j == n) ? -1 : a[j];
    long long int temp = 0;
    if (cnt >= k) {
      temp = (cnt / k) * x + (cnt % k) * y;
      if (ma < left or ma < right) {
        temp = min(temp, cnt * y);
      }
      temp = min(temp, x + (cnt - k) * y);
      ans += temp;
    } else {
      if (ma > left and ma > right) {
        possible = false;
        break;
      }
      ans += cnt * y;
    }
    i = j;
  }
  if (possible)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int testcases = 1;
  while (testcases--) {
    solve();
  }
}
