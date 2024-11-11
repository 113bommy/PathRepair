#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
using namespace std;
long long inv(long long a, long long b) {
  return 1 < a ? b - inv(b % a, a) * b / a : 1;
}
long long Pow(long long B, long long P) {
  long long R = 1;
  while (P > 0) {
    if (P & 1) R = (R * B);
    P /= 2;
    B = (B * B);
  }
  return R;
}
long long GCD(long long a, long long b) {
  while (b) {
    b ^= a ^= b ^= a %= b;
  }
  return a;
}
long long LCM(long long a, long long b) { return (a / GCD(a, b) * b); }
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P & 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return (long long)R;
}
void flp(vector<char>& a, int n) {
  for (long long i = 0; i < n; ++i) a[i] = a[i] == '0' ? '1' : '0';
  for (long long i = 0; i < n / 2; ++i) {
    swap(a[i], a[n - i - 1]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<char> a(n), b(n);
    for (long long i = 0; i < n; ++i) cin >> a[i];
    for (long long i = 0; i < n; ++i) cin >> b[i];
    vector<int> ans;
    for (long long i = n - 1; i >= 0; --i)
      if (a[i] != b[i]) {
        if (a[0] != b[i]) {
          ans.push_back(i + 1);
          flp(a, i + 1);
        } else {
          ans.push_back(1);
          ans.push_back(i + 1);
          flp(a, 1);
          flp(a, i + 1);
        }
      }
    cout << ans.size() << " ";
    for (int x : ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
