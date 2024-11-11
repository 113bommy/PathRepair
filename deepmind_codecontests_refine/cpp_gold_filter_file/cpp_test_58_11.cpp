#include <bits/stdc++.h>
using namespace std;
vector<long long> factors;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  res *= res;
  if (b % 2 == 0)
    return res;
  else
    return (res * a);
}
long long binpow_Mod(long long a, long long b) {
  if (b == 0) return 1;
  long long res = (binpow_Mod(a, b / 2)) % 1000000007;
  res *= res;
  res %= 1000000007;
  if (b % 2 == 0)
    return res;
  else
    return ((res * a) % 1000000007);
}
long long HCF(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return HCF(b % a, a);
}
long long LCM(long long a, long long b) { return ((a * b) / HCF(a, b)); }
bool sortbysec(const pair<long long, long long>& a,
               const pair<long long, long long>& b) {
  return (a.second < b.second);
}
void factorise(long long a) {
  factors.clear();
  for (long long i = 1; i * i <= a; i++) {
    if (i * i == a)
      factors.push_back(i);
    else if (a % i == 0) {
      factors.push_back(i);
      factors.push_back(a / i);
    }
    sort(factors.begin(), factors.end());
  }
}
int main() {
  FAST();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool ans = true;
    for (long long i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        ans = false;
        break;
      }
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
