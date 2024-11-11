#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
const unsigned long long int mod = 1e9 + 7;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res % mod;
}
vector<long long int> arr, ans1, ans;
long long int res = 0, total;
long long int get(long long int x) {
  if (x == arr[x]) return arr[x];
  return get(arr[x]);
}
void merge(long long int a, long long int b, long long int kk[]) {
  long long int t1 = a, t2 = b;
  if (a == b) return;
  a = get(a);
  b = get(b);
  if (a == b) {
    return;
  }
  arr[b] = a;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  t = 1;
  while (t--) {
    long long int n, k = -1;
    cin >> n;
    long long int kk[n], aa[n];
    arr.resize(n);
    for (long long int i = 0; i < n; i++) arr[i] = i;
    bool flag = true;
    for (long long int i = 0; i < n; i++) {
      cin >> kk[i];
      aa[i] = kk[i];
      if (kk[i] == i + 1) {
        if (flag)
          k = i;
        else
          ans.push_back(i);
        flag = false;
      } else if (get(i) == get(kk[i] - 1)) {
        ans.push_back(i);
      } else
        merge(kk[i] - 1, i, kk);
    }
    long long int i = 0;
    if (k == -1) k = ans[0], i = 1, kk[ans[0]] = ans[0];
    for (i; i < ans.size(); i++) {
      kk[ans[i]] = k;
    }
    for (long long int i = 0; i < n; i++) {
      if (kk[i] != aa[i]) res++;
    }
    cout << res << '\n';
    for (auto x : kk) cout << x << " ";
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
