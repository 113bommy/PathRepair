#include <bits/stdc++.h>
using namespace std;
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void code() {
  string s;
  cin >> s;
  long long n = s.length();
  YES(n % 2 == 0 && s[0] != ')' && s[n - 1] != '(');
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m);
  long long x = 0, y = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    x ^= a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    y ^= b[i];
  }
  if (x != y) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  long long last = 0;
  for (long long i = 1; i < n; i++) {
    for (long long j = 1; j < m; j++) cout << 0 << " ";
    cout << a[i - 1] << endl;
    last ^= a[i - 1];
  }
  for (long long i = 1; i < m; i++) cout << b[i - 1] << " ";
  last ^= b[m - 1];
  cout << last << endl;
}
