#include <bits/stdc++.h>
using namespace std;
void edit(vector<int> &skill, int n) {
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    skill.push_back(x);
  }
}
void editl(vector<long long> &skill, long long n) {
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    skill.push_back(x);
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
bool isGoogles = 0;
bool testcase = 1;
void achilles() {
  string t;
  cin >> t;
  long long n;
  n = stol(t);
  long long x = 1;
  long long mn = 1e9;
  long long mni = 0;
  for (long long i = 0; i < 40; i++) {
    x = 1LL << i;
    string s = to_string(x);
    long long mat = 0;
    long long u = s.size();
    long long v = t.size();
    long long prev = 0;
    for (long long p = 0; p < u; p++) {
      bool flag = false;
      for (long long q = prev; q < v; q++) {
        if (s[p] == t[q]) {
          prev = q + 1;
          mat++;
          flag = true;
          break;
        }
      }
      if (!flag) break;
    }
    long long o = v - mat + u - mat;
    if (o < mn) {
      mn = o;
      mni = x;
    }
  }
  cout << mn << "\n";
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1, w = 1;
  if (testcase) cin >> t;
  while (t--) {
    if (isGoogles) {
      cout << "Case #" << w << ": ";
    }
    achilles();
    w++;
  }
  return 0;
}
