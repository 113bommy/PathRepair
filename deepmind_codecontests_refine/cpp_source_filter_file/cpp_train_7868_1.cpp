#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, s = 0;
  cin >> n;
  vector<long long> a(n, 0);
  for (long long i = 0; i < n; i += 1) {
    cin >> a[i];
    s += a[i];
  }
  if (s & 1) {
    cout << "NO";
    return 0;
  }
  map<long long, long long> first, second;
  first[a[0]] = 1;
  for (long long i = 1; i < n; i += 1) second[a[i]]++;
  long long sp = 0;
  for (long long i = 0; i < n - 1; i += 1) {
    sp += a[i];
    if (sp == s / 2) {
      cout << "YES";
      return 0;
    }
    if (sp < s / 2) {
      long long x = s / 2 - sp;
      if (second[x] > 0) {
        cout << "YES";
        return 0;
      }
    } else {
      long long y = sp - s / 2;
      if (first[y] > 0) {
        cout << "YES";
        return 0;
      }
    }
    first[a[i + 1]]++;
    second[a[i + 1]]--;
  }
  cout << "NO";
  return 0;
}
