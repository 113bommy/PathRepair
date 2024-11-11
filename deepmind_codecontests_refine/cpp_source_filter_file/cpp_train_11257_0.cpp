#include <bits/stdc++.h>
using namespace std;
long long n, k, a[30], sum = 1, maxi;
int main() {
  string s;
  cin >> n >> k >> s;
  for (long long i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      sum++;
    else
      sum = 1;
    if (sum == k) a[s[i] - 'a']++, sum = 0;
  }
  for (long long i = 0; i < 26; i++) maxi = max(maxi, a[i]);
  cout << maxi << endl;
  return 0;
}
