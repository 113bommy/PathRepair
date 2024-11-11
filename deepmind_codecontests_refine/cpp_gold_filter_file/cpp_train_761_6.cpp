#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int n) {
  if (x % 2 == n % 2) {
    if (x % 2) {
      if (x > n) return 1;
      return 0;
    } else {
      if (n > x) return 1;
      return 0;
    }
  }
  if (x % 2) return 1;
  return 0;
}
bool cmp1(int x, int y) {
  if (x > y)
    return 1;
  else
    return 0;
}
bool compchar(string s) {
  for (int i = 0; i < s.size() - 1; i++) return s[i] > s[i + 1];
}
bool issubstring(string sub, string a) {
  for (int i = 0; i < a.size(); i++) {
    string test;
    for (int j = i; j < a.size(); j++) {
      test.push_back(a[j]);
      if (test == sub) return true;
    }
  }
}
const int N = 2005;
bool test[N][N];
int x[3005], y[3005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    test[x[i] + 1000][y[i] + 1000] = true;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((x[i] + x[j]) % 2 != 0 || (y[j] + y[i]) % 2 != 0) continue;
      int midX = (x[i] + x[j]) / 2;
      int midY = (y[i] + y[j]) / 2;
      if (test[midX + 1000][midY + 1000]) ans++;
    }
  }
  cout << ans;
}
