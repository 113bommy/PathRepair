#include <bits/stdc++.h>
using namespace std;
int str(string& s1, string& s2) {
  int n = s1.length(), m = s2.length();
  int i = 0, j = 0;
  while (i < n) {
    if (s1[i] == s2[j]) ++j;
    if (j == m) break;
    ++i;
  }
  return j;
}
const int N = 50;
string a[N];
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < N; ++i) {
    long long num = 1LL << i;
    a[i] = to_string(num);
  }
  while (t) {
    --t;
    string num;
    cin >> num;
    int n = num.length();
    int ans = 30;
    for (int i = 0; i < N; ++i) {
      int len = str(num, a[i]);
      int minN = n + a[i].length() - 2 * len;
      ans = min(ans, minN);
    }
    cout << ans << endl;
  }
  return 0;
}
