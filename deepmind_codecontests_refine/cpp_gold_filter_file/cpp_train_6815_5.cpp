#include <bits/stdc++.h>
using namespace std;
bool checkBit(long long int n, long long int i) { return (n & (1LL << i)); }
long long int setBit(long long int n, long long int i) {
  return (n | (1LL << i));
}
long long int resetBit(long long int n, long long int i) {
  return (n & (~(1LL << i)));
}
long long int pref_a[1000003], suf_b[1000003];
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  long long int a, b;
  cin >> a >> b;
  long long int temp = 0;
  for (int i = 0; i < n; i++) {
    temp = temp * 10LL + s[i] - '0';
    temp %= a;
    pref_a[i] = temp;
  }
  temp = 0;
  long long int p = 1;
  for (int i = n - 1; i >= 0; i--) {
    suf_b[i] = (p * (s[i] - '0') + suf_b[i + 1]) % b;
    p *= 10LL;
    p %= b;
  }
  int div = -1;
  for (int i = 0; i < n - 1; i++) {
    if (pref_a[i] == 0 and suf_b[i + 1] == 0 and s[0] != '0' and
        s[i + 1] != '0') {
      div = i;
      break;
    }
  }
  if (div == -1) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
    for (int i = 0; i <= div; i++) {
      cout << s[i];
    }
    cout << "\n";
    for (int i = div + 1; i < n; i++) {
      cout << s[i];
    }
    cout << "\n";
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
