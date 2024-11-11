#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int noofdig(int N) { return floor(log10(N)) + 1; }
bool ispow2(int x) { return x && (!(x & (x - 1))); }
bool isVowel(char c) {
  if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' ||
      c == 'o' || c == 'O' || c == 'u' || c == 'U')
    return true;
  return false;
}
bool issqr(float y) {
  if (sqrt(abs(y)) == floor(sqrt(abs(y)))) return true;
  return false;
}
void printDivisors(int n) {
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        printf("%d ", i);
      else
        printf("%d %d ", i, n / i);
    }
  }
}
void removeSubstrs(string& s, string& p) {
  string::size_type n = p.length();
  for (string::size_type i = s.find(p); i != string::npos; i = s.find(p))
    s.erase(i, n);
}
int countone(unsigned int u) {
  unsigned int uCount;
  uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
  return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    vector<int> x;
    long long int cnt = 2;
    long long int t = 2;
    x.push_back(cnt);
    while (cnt <= n) {
      cnt += (3 * t) + (t - 1);
      x.push_back(cnt);
      t += 2;
    }
    long long int res = 0;
    if (n >= 2) {
      for (int i = x.size() - 1; i >= 0; i--) {
        res += n / x[i];
        n = n % x[i];
      }
      cout << res << endl;
    } else
      cout << 0 << endl;
  }
  return 0;
}
