#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long int inf = 1e9 + 7;
const long long int mod = 998244353;
map<long long int, long long int>::iterator it;
long long int read() {
  long long int x;
  scanf("%lld", &x);
  return x;
}
string c2s(char c) {
  string re = "0";
  re[0] = c;
  return re;
}
long long int printv(vector<long long int> V) {
  cout << V.size() << ": ";
  for (long long int i = 0; i < V.size(); i++) cout << V[i] << " ";
  puts("");
}
long long int gcd(long long int x, long long int y) {
  while (x % y) {
    long long int t = x % y;
    x = y;
    y = t;
  }
  return y;
}
long long int readv(vector<long long int>& V) {
  for (long long int i = 0; i < ((long long int)V.size()); i++) V[i] = read();
}
bool isprime(long long int x) {
  for (long long int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
void yn(bool x) {
  if (x)
    puts("YES");
  else
    puts("NO");
}
long long int fpow(long long int a, long long int n) {
  long long int re = 1;
  while (n) {
    if (n & 1) re = re * a % mod;
    a = a * a % mod;
    n /= 2;
  }
  return re;
}
const long long int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const long long int dir2[8][2] = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                                  {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
long long int fff(long long int x) {
  if (x > 0)
    return (x + 1) / 2;
  else
    return ((-1) * x) / 2 * (-1);
}
int main() {
  long long int ca = read();
  for (long long int ci = 0; ci < ca; ci++) {
    long long int n = read(), k = read();
    string t;
    cin >> t;
    long long int lcnt = 0, wcnt = 0;
    long long int winpos = -1;
    vector<long long int> A;
    for (long long int i = 0; i < ((long long int)t.size()); i++) {
      if (t[i] == 'L')
        lcnt++;
      else {
        wcnt++;
        if (winpos != -1 && winpos + 1 != i) A.push_back(i - winpos - 1);
        winpos = i;
      }
    }
    sort(A.begin(), A.end());
    if (lcnt <= k)
      cout << 2 * n - 1 << endl;
    else if (wcnt == 0 && k)
      cout << 2 * k - 1 << endl;
    else {
      long long int presco = 0;
      long long int pre = 0;
      for (long long int i = 0; i < n; i++) {
        if (t[i] == 'W' && pre) presco += 2;
        if (t[i] == 'W' && pre == 0) presco++;
        if (t[i] == 'W') pre = 1;
        if (t[i] == 'L') pre = 0;
      }
      long long int ans = presco + 2 * k;
      if (k) {
        long long int i = 0;
        while (i + 1 <= A.size() && k >= A[i]) {
          k -= A[i++];
          ans++;
        }
      }
      cout << ans << endl;
    }
  }
}
