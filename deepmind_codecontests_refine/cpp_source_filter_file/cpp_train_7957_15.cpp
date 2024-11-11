#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  unsigned long long k;
  cin >> k;
  unsigned long long a[27];
  for (unsigned long long i = 0; i < 26; i++) {
    cin >> a[i];
  }
  unsigned long long f = 0;
  unsigned long long n = s.size();
  for (unsigned long long i = 0; i < n; i++) {
    f = f + (a[s[i] - 'a'] * (i + 1));
  }
  sort(a, a + n, greater<int>());
  unsigned long long j = n + 1;
  for (unsigned long long i = 0; i < k; i++) {
    f = f + (a[0] * j);
    j++;
  }
  cout << f << endl;
}
