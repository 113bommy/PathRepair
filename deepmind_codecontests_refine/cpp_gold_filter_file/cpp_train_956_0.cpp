#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void debug() { cout << endl; }
template <class T1, class... Types>
void debug(T1 e1, Types... e2) {
  cout << e1 << " ";
  debug(e2...);
}
template <class T>
void displayvector(vector<T> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
template <class T>
void displayarray(T *v, int n) {
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
template <class T>
int sizeofarr(T *v) {
  return sizeof(v) / sizeof(T);
}
signed main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, d;
  cin >> n >> m >> d;
  long long int temp = n;
  vector<int> arr(m);
  vector<int> ans(n);
  for (int i = 0; i < m; i++) cin >> arr[i];
  vector<int> prefixsum(m);
  prefixsum[0] = arr[0];
  for (int i = 1; i < arr.size(); i++) prefixsum[i] = prefixsum[i - 1] + arr[i];
  long long int standing = n;
  for (long long int i = arr.size() - 1; i >= 0; i--) {
    n = n - d - arr[i] + 1;
  }
  n -= d - 1;
  if (n > 0) {
    cout << "NO\n";
    return 0;
  }
  if (d >= temp) {
    long long int v = 0;
    for (int i = 0; i < m; i++) {
      for (int u = 0; u < arr[i]; u++) {
        ans[v] = i + 1;
        v++;
      }
    }
    cout << "YES\n";
    displayvector(ans);
    return 0;
  }
  standing = temp;
  for (long long int i = arr.size() - 1; i >= 0; i--) {
    long long int jump = 0;
    for (int j = 1; j <= d; j++) {
      if (standing - j + 1 >= prefixsum[i]) jump = j;
    }
    for (int k = standing - jump; k > standing - jump - arr[i]; k--)
      ans[k] = i + 1;
    standing = standing - jump - arr[i] + 1;
  }
  cout << "YES\n";
  displayvector(ans);
  return 0;
}
