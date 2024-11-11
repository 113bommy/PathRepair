#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  string s;
  cin >> s;
  long long n = s.length();
  vector<long long> p(n, 0);
  for (long long i = 1; i < n; i++) {
    long long j = p[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = p[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    p[i] = j;
  }
  if (p[n - 1] == 0) {
    cout << "Just a legend";
    return 0;
  }
  for (long long i = 1; i < n - 1; i++) {
    if (p[i] == p[n - 1]) {
      for (long long j = 0; j < p[i]; j++) {
        cout << s[j];
      }
      return 0;
    }
  }
  if (p[p[n - 1] - 1] == 0) {
    cout << "Just a legend";
    return 0;
  }
  long long x = p[p[n - 1] - 1];
  for (long long i = 0; i < x; i++) {
    cout << s[i];
  }
}
