#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000007;
long long INFLL = (long long)INF * (long long)INF;
long double EPS = 10e-9;
long double pi = 2 * acos(0.0);
long long Power(long long $a, long long $b) {
  long long $result = 1;
  $a %= 998244353;
  while ($b) {
    if ($b % 2 == 1) $result *= $a;
    $a *= $a;
    $a %= 998244353;
    $result %= 998244353;
    $b /= 2;
  }
  return $result;
}
long long Mod_Inv(long long $a) {
  $a %= 998244353;
  $a = Power($a, 998244353 - 2);
  return $a;
}
long long Factorial[500001];
long long Make_Factorial() {
  Factorial[0] = 1;
  for (long long i = 1; i < 500001; i++) {
    Factorial[i] = i * Factorial[i - 1];
    Factorial[i] %= 998244353;
  }
  return 0;
}
long long Implement_Make_Factorial = Make_Factorial();
long long nCr(long long $n, long long $r) {
  if ($n < $r) return 0;
  long long $ans = Factorial[$n];
  $ans %= 998244353;
  $ans *= Mod_Inv(Factorial[$r]);
  $ans %= 998244353;
  $ans *= Mod_Inv(Factorial[$n - $r]);
  $ans %= 998244353;
  return $ans;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  std::map<long long, long long> freq;
  for (long long i = 0; i < n; ++i) {
    freq[a[i]]++;
  }
  set<long long> v;
  long long store = -1;
  for (auto ash : freq) {
    if (ash.second == 1) {
      v.insert(ash.first);
    } else if (ash.second > 2) {
      store = ash.first;
    }
  }
  if (v.size() % 2 == 1 and store == -1) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  long long temp = v.size();
  long long sz = v.size();
  sz /= 2;
  char ans[n];
  for (long long i = 0; i < n; ++i) {
    if (v.find(a[i]) == v.end()) {
      if (temp % 2 == 1 and store == a[i]) {
        ans[i] = 'B';
        store = -1;
        continue;
      }
      ans[i] = 'A';
      continue;
    }
    if (v.size() > sz) {
      ans[i] = 'A';
      v.erase(a[i]);
    } else {
      ans[i] = 'B';
    }
  }
  for (long long i = 0; i < n; ++i) {
    cout << ans[i];
  }
}
int32_t main() {
  clock_t start, end;
  start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "\nTime taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec "
       << "\n";
  return 0;
}
