#include <bits/stdc++.h>
using namespace std;
long long int __gcd(long long int a, long long int b) {
  return (a % b) ? __gcd(b, a % b) : b;
}
bool prime(long long int k) {
  for (long long int i = 2; i * i <= k; i++)
    if (k % i == 0) {
      return false;
    }
  return true;
}
void pdash(int n = 1) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
void solve() {
  int n;
  string cmp = "aeiou";
  cin >> n;
  string str;
  cin >> str;
  string ans = "";
  for (int i = 0, j = 0; i < n && j < n;) {
    bool iv = 0;
    for (int k = 0; k < 5; k++) {
      if (str[i] == cmp[k]) {
        iv = 1;
        break;
      }
    }
    if (!iv) {
      ans += string(str.begin() + i, str.begin() + i + 1);
      i++;
      j++;
      continue;
    }
    while (str[i] == str[j] and j < n) {
      j++;
    }
    if (j - i == 2 and (str[i] == 'e' || str[i] == 'o')) {
      ans += string(str.begin() + i, str.begin() + (i + 2));
    } else {
      ans += string(str.begin() + i, str.begin() + i + 1);
    }
    i = j;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
}
