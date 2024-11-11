#include <bits/stdc++.h>
using namespace std;
bool palindrome(string s) {
  if (s.length() == 1) return true;
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      cout << sum + a[i] << " ";
    } else {
      sum += a[i];
      cout << sum << " ";
    }
  }
}
