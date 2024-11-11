#include <bits/stdc++.h>
using namespace std;
long long int Mgcd(long long int a, long long int b) {
  if (b == 0) return a;
  return Mgcd(b, a % b);
}
long long int Mlcm(long long int a, long long int b) {
  return (a * b) / Mgcd(a, b);
}
long long int i, j;
void solve() {
  string s;
  cin >> s;
  vector<long long int> a(26, 0);
  for (i = 0; i < 26; i++) a[s[i] - 'a']++;
  for (i = 25; i >= 0; i--) {
    if (a[i]) {
      for (j = 0; j < a[i]; j++) cout << char('a' + i);
      break;
    }
  }
}
int main() { solve(); }
