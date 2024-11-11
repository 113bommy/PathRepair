#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b) {
  return a.second < b.second;
}
long long gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool isprime(long long a) {
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return 1;
  return 0;
}
int fact(int n) {
  int a = 1, i;
  for (i = 2; a < n; i++) a = a * i;
  return i - 1;
}
unsigned long long factorial(int a) {
  unsigned long long ans = 1;
  for (int i = 2; i <= a; i++) ans = i * ans;
  return ans;
}
void solve() {
  int n, i, flag = 0;
  cin >> n;
  int a[n];
  for (auto& i : a) cin >> i;
  for (i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    for (int j = i + 1; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        cout << -1;
        return;
      }
    }
  }
  if (a[0] < a[n - 1])
    cout << -1;
  else
    cout << n - i - 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
