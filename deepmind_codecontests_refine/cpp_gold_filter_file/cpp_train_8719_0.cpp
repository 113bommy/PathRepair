#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
unsigned long long int pow1(unsigned long long int a, unsigned long long int b,
                            unsigned long long int c) {
  unsigned long long int ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= c;
    }
    b /= 2;
    a = a * a;
    a %= c;
  }
  return ans;
}
long long int gcd(unsigned long long int a, unsigned long long int b) {
  unsigned long long int t = a;
  a = min(a, b);
  b = max(b, t);
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
unsigned long long int fct(unsigned long long int k) {
  unsigned long long int a = 1;
  for (long long int i = 2; i < k + 1; i++) {
    a *= i;
    a %= 1000000007;
  }
  return a;
}
unsigned long long int C(unsigned long long int n, unsigned long long int r) {
  if (n < r)
    return 0;
  else if (n == r || r == 0)
    return 1;
  vector<vector<unsigned long long int> > v(
      n + 1, vector<unsigned long long int>(r + 1));
  for (long long int i = 0; i < n + 1; i++) v[i][0] = 1;
  for (long long int i = 0; i < r + 1; i++) v[0][i] = 1;
  for (long long int i = 1; i < n + 1; i++) {
    for (long long int j = 1; j < min(i, (long long int)r) + 1; j++) {
      if (i == j)
        v[i][j] = 1;
      else if (j == 1)
        v[i][j] = i;
      else
        v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % 1000000007;
    }
  }
  return v[n][r] % 1000000007;
}
char ass(char a) {
  if (a == 'a' || a == 'c') return 'b';
  return 'a';
}
char assn(char a, char b) {
  if (a == 'a') {
    if (b == 'b')
      return 'c';
    else
      return 'b';
  } else if (a == 'b') {
    if (b == 'a')
      return 'c';
    else
      return 'a';
  } else {
    if (b == 'a')
      return 'b';
    else
      return 'a';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  map<string, string> mp;
  mp["green"] = "Time";
  mp["blue"] = "Space";
  mp["orange"] = "Soul";
  mp["red"] = "Reality";
  mp["yellow"] = "Mind";
  mp["purple"] = "Power";
  int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    string h;
    cin >> h;
    mp.erase(h);
  }
  cout << mp.size() << endl;
  for (auto& x : mp) {
    cout << x.second << endl;
  }
}
