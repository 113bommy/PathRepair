#include <bits/stdc++.h>
using namespace std;
const long long OO = 5e16;
long long fastPow(long long a, long long p) {
  if (p == 0) return 1;
  long long ans = fastPow(a, p / 2);
  ans *= ans;
  if (p & 1) ans *= a;
  return ans;
}
long long E_GCD(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long g = E_GCD(b % a, a, y, x);
  x = x - (b / a) * y;
  return g;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long phi1(long long n) {
  long long ans = 1;
  for (int i = 2; i < n; i++)
    if (gcd(n, i) == 1) ans++;
  return ans;
}
long long phi2(long long n) {
  long long ans = 1;
  vector<bool> primes(n + 1, 1);
  for (int i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (int j = 2 * i; j <= n; j += i) primes[j] = 0;
      int p_to_k = 0;
      if (!(n % i)) {
        while (!(n % i)) p_to_k++, n /= i;
        ans *= fastPow(i, p_to_k - 1) * (i - 1);
      }
    }
  }
  if (n > 1) ans *= n - 1;
  return ans;
}
const int MAXNUM = 100000;
long long phiArr[MAXNUM];
void phiRange() {
  fill_n(phiArr, sizeof(phiArr) / sizeof(*phiArr), 1);
  vector<bool> primes(MAXNUM + 1, 1);
  for (int i = 2; i * i <= MAXNUM; i++) {
    if (primes[i]) {
      phiArr[i] = i - 1;
      for (int j = i * 2; j <= MAXNUM; j += i) {
        primes[j] = false;
        long long pow = 0;
        long long val = j;
        while (!(val % i)) pow++, val /= i;
        phiArr[j] *= fastPow(i, pow - 1) * (i - 1);
      }
    }
  }
}
bool isPrime(long long a) {
  for (int i = 2; i * i <= a; i++)
    if (!(a % i)) return false;
  return true;
}
long long modInv(long long a, long long m) {
  int x, y;
  long long g = E_GCD(a, m, x, y);
  if (g > 1) return -1;
  return (x % m + m) % m;
}
long long modInv2(long long a, long long m) { return fastPow(a, m - 2) % m; }
int indexInFreeSqList(int n) {
  vector<int> moe(n + 1, 1);
  vector<bool> primes(n + 1, true);
  moe[1] = -1;
  for (int i = 2; i * i <= n; i++) {
    if (primes[i]) {
      moe[i] = -1;
      for (int j = i * 2; j <= n; j += i) {
        primes[j] = false;
        moe[j] = (j % (i * i) == 0) ? 0 : -moe[j];
      }
    }
  }
  int index = 0;
  for (int i = 1; i <= n; i++)
    if (moe[i] != 0) index++;
  return index;
}
const int MOD = 998244353;
long long powMod(long long b, long long e) {
  if (!e) return 1;
  long long ret = powMod(b, e >> 1);
  ret = ret * ret % MOD;
  if (e & 1) ret = ret * b % MOD;
  return ret % MOD;
}
long long modInv(long long a) { return powMod(a, MOD - 2) % MOD; }
const int N = 2e5;
long long fac[N + 1];
long long invfac[N + 1];
void fillfac() {
  fac[0] = 1;
  for (int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * i;
}
int toBePalindrome(string& s, int i, int j) {
  int diffs = 0;
  int len = (int)s.size();
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - i - 1]) {
      diffs++;
      s[i] = s[len - i - 1];
    }
  }
  return diffs;
}
string text;
vector<vector<pair<int, vector<string>>>> memo(
    500, vector<pair<int, vector<string>>>(500, {-1, vector<string>(0)}));
pair<int, vector<string>> divide(int remSplits, int index) {
  if (remSplits >= 1 && index == (int)text.size()) return {1000, {}};
  if (remSplits == 1) {
    int cost = 0;
    string lastWord = text.substr(index, (int)text.size() - index);
    cost += toBePalindrome(lastWord, index, (int)text.size() - 1);
    return {cost, {lastWord}};
  }
  if (memo[remSplits][index].first != -1) return memo[remSplits][index];
  pair<int, vector<string>> ans;
  pair<int, vector<string>> bestRem;
  ans.first = 600;
  bestRem.first = 1000;
  string bestWord;
  int bestCost = 1000;
  for (int i = index; i < (int)text.size(); i++) {
    pair<int, vector<string>> temp;
    temp.first = 1000;
    string ourWord = text.substr(index, i + 1 - index);
    int cost = toBePalindrome(ourWord, index, i);
    temp = divide(remSplits - 1, i + 1);
    if (temp.first + cost < bestCost) {
      bestCost = temp.first + cost;
      bestRem = temp;
      bestWord = ourWord;
    }
  }
  ans.first = bestCost;
  ;
  ans.second.push_back(bestWord);
  for (auto& x : bestRem.second) ans.second.push_back(x);
  return memo[remSplits][index] = ans;
}
int solve(int tt) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != '0') {
      ans++;
      ans += s[i] - '0';
    }
  }
  if (s[n - 1] != '0') ans += s[n - 1] - '0';
  cout << ans << endl;
  return 0;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int tt = 1;
  if (1) cin >> tt;
  for (int i = 1; i <= tt; i++) {
    solve(tt);
  }
  return 0;
}
