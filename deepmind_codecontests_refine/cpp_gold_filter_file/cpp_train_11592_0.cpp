#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5 + 10;
const long long INF = 1e9 + 10;
const long long mod = 1e18;
ofstream out("output.txt");
ifstream in("intput.txt");
long long bpow(long long t, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = (ans * t) % mod;
    t = (t * t) % mod, n >>= 1;
  }
  return ans;
}
bool mark[MAX_N];
long long a[100], k, n;
long long temp[100][100];
void print(long long n, vector<long long> ans) {
  if (ans.size() == n) {
    if (k == 3) {
      long long t1 = a[ans[0]] + a[ans[1]] + a[ans[2]],
                t2 = a[ans[3]] + a[ans[4]] + a[ans[5]],
                t3 = a[ans[6]] + a[ans[7]] + a[ans[8]],
                t4 = a[ans[0]] + a[ans[3]] + a[ans[6]],
                t5 = a[ans[1]] + a[ans[4]] + a[ans[7]],
                t6 = a[ans[2]] + a[ans[5]] + a[ans[8]],
                t7 = a[ans[0]] + a[ans[4]] + a[ans[8]],
                t8 = a[ans[6]] + a[ans[4]] + a[ans[2]];
      if (t1 == t2 && t2 == t3 && t3 == t4 && t4 == t5 && t6 == t7 &&
          t7 == t8) {
        cout << t1;
        for (long long i = 0; i < n; i++) {
          if (i % k == 0) cout << endl;
          cout << a[ans[i]] << " ";
        }
        exit(0);
      }
    }
    return;
  }
  for (long long i = 0; i < n; i++) {
    if (!mark[i]) {
      mark[i] = true;
      ans.push_back(i);
      print(n, ans);
      ans.pop_back();
      mark[i] = false;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(12);
  cin >> k;
  for (long long i = 0; i < k * k; i++) cin >> a[i];
  if (k == 1) {
    cout << a[0] << "\n" << a[0];
    return 0;
  } else if (k == 2) {
    cout << 2 * a[0] << endl;
    cout << a[0] << " " << a[0] << endl;
    cout << a[0] << " " << a[0];
    return 0;
  }
  n = k * k;
  vector<long long> vec;
  print(n, vec);
}
