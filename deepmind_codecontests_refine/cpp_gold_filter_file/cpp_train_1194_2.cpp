#include <bits/stdc++.h>
using namespace std;
const long long P = 1000000007;
long long power(int a, int b) {
  long long res = 1;
  for (int i = 0; i < b; i++) {
    res = res * a % P;
  }
  return res;
}
long long solve() {
  ios::sync_with_stdio(false);
  int n;
  string s;
  map<char, int> m;
  cin >> n >> s;
  for (int i = 0; i < 26; i++) {
    m[(char)'A' + i] = 0;
  }
  int sum = 0, maxi = -1;
  for (int i = 0; i < s.length(); i++) {
    m[s[i]]++;
    if (m[s[i]] > maxi) {
      maxi = m[s[i]];
      sum = 1;
    } else if (m[s[i]] == maxi)
      sum++;
  }
  long long res = power(sum, n);
  return res;
}
int main() { cout << solve(); }
