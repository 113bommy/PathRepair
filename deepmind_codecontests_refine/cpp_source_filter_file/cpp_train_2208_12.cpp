#include <bits/stdc++.h>
using namespace std;
long long digits(long long n) {
  long long cnt = 0;
  while (n > 0) {
    cnt++;
    n = n / 10;
  }
  return cnt;
}
long long modularExponentiation(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      result = ((result) * (x));
    }
    x = ((x) * (x));
    n = n / 2;
  }
  return result;
}
bool ispower(long long n) {
  if (n == 1) return true;
  if (n % 2 == 1) return false;
  while (n > 1) {
    if (n % 2 == 1) return false;
    n = n / 2;
  }
  return true;
}
long long nck(long long n, long long k) {
  long long C[n + 1][k + 1];
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
int32_t main() {
  long long t;
  cin >> t;
  string s1 = "one";
  string s2 = "two";
  string s3 = "twone";
  while (t--) {
    string s;
    cin >> s;
    long long n = s.size();
    vector<long long> ans;
    long long i = 0;
    while (i < n) {
      bool ok = false;
      if (i + 5 <= n) {
        string temp = "";
        for (long long j = i; j < i + 5; j++) temp += s[j];
        if (temp == s3) {
          ans.push_back(i + 2);
          i += 5;
          ok = true;
        }
      }
      if (i + 3 <= n && !ok) {
        string temp = "";
        for (long long j = i; j < i + 3; j++) temp += s[j];
        if (temp == s1 || temp == s2) {
          ans.push_back(i);
          i += 3;
          ok = true;
        }
      }
      if (!ok) i++;
    }
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
    cout << endl;
  }
}
