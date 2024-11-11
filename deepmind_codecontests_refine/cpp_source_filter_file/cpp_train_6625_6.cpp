#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string a, b;
  cin >> a >> b;
  map<char, long long> m;
  for (long long i = 0; i < a.length(); i++) m[a[i]] = 1;
  bool ok = true;
  for (long long i = 0; i < b.length(); i++)
    if (!m[b[i]]) ok = false;
  if (ok) {
    vector<long long> v[26];
    for (long long i = 0; i < a.length(); i++) v[a[i] - 'a'].push_back(i);
    long long count = 1;
    long long temp = -1;
    for (long long i = 0; i < b.length(); i++) {
      long long flag = b[i] - 'a';
      long long pos =
          lower_bound(v[flag].begin(), v[flag].end(), temp) - v[flag].begin();
      if (pos == v[flag].size()) {
        count++;
        temp = v[flag][0];
      } else {
        temp = v[flag][pos];
      }
    }
    cout << count << "\n";
  } else
    cout << -1 << "\n";
}
