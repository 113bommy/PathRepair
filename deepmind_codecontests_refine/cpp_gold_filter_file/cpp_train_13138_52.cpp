#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long n = s.length();
  vector<long long> pi(n + 1);
  pi.push_back(0);
  long long j;
  for (long long i = 1; i < n; i++) {
    j = pi[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  if (pi[n - 1] == 0 || n == 1 || n == 2) {
    cout << "Just a legend";
  } else {
    long long ans = 0, temp = 0;
    for (long long i = 1; i < n - 1; i++) {
      if (temp < pi[i]) temp = pi[i];
    }
    if (temp >= pi[n - 1]) {
      ans = pi[n - 1];
    } else {
      ans = pi[pi[n - 1] - 1];
    }
    if (ans == 0)
      cout << "Just a legend";
    else {
      for (long long i = 0; i < ans; i++) cout << s[i];
    }
  }
}
