#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
const long long mod = 1e18;
long long power(long long a, long long b) {
  if (b == 0) return 1LL;
  long long d = power(a, b / 2);
  d *= d;
  d %= mod;
  if (b % 2) d *= a;
  d %= mod;
  return d;
}
long long inv(long long a, long long MOD) { return power(a, MOD - 2); }
long long bs(long long a[], long long n, long long key) {
  long long s = 1;
  long long e = n;
  while (s <= e) {
    long long mid = (s + e) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] > key)
      e = mid - 1;
    else
      s = mid + 1;
  }
  return -1;
}
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(8);
  cout << fixed;
  cin >> s;
  string a[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
  set<string> res;
  for (string j : a) {
    res.insert(j);
  }
  int cnt = 0;
  multiset<string> fin;
  for (long long i = 1; i <= s.length(); i++) {
    for (long long j = 0; j <= s.length() - 1; j++) {
      if (i + j > s.length()) break;
      string str = s.substr(j, i);
      fin.insert(str);
    }
  }
  for (auto j : fin) {
    if (res.find(j) != res.end()) cnt++;
  }
  if (cnt == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
